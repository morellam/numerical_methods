#include<iostream>
#include<cmath>
#include<vector>	
#include<fstream>



std::vector<double> linspace(double x_min, double x_max, double spacing){
	int N = (x_max - x_min) / spacing;

	std::vector<double> x(N, 0.);	
	for(int i = 0; i < x.size(); i++){
		x[i] =  x_min + (double)i * spacing;
	}
	return x;
}


inline double simpleCos(double x) { return  cos(0.5 * M_PI * x); }


std::vector<double> sourceTerm(double D, std::vector<double> x) {
	std::vector<double> output(x.size(), 0.);
	for(int i = 0; i < x.size(); i++){
		output[i] = pow(M_PI, 2) * 0.25 * D * cos(0.5 * M_PI * x[i]); 
	}

	return output; 
}

double rms(std::vector<double> x, std::vector<double> numerical){
	
	double rms = 0.;

	for(int i = 0; i < x.size(); i++) rms += pow(simpleCos(x[i]) - numerical[i], 2.);
	
	return sqrt(rms/(double)x.size());
}


int solve_tridiag_nonsym(const std::vector<double>& diag, const std::vector<double>& abovediag,
                         const std::vector<double>& belowdiag, const std::vector<double>& rhs, std::vector<double>& x,
                         size_t N) {
	int status = 0;
  	std::vector<double> alpha(N);
  	std::vector<double> z(N);

  	size_t i, j;

 	alpha[0] = diag[0];
 	z[0] = rhs[0];
 	if (alpha[0] == 0) {
 		status = 1;
 	}	

  	for (i = 1; i < N; i++) {
    		const double t = belowdiag[i - 1] / alpha[i - 1];
    		alpha[i] = diag[i] - t * abovediag[i - 1];
    		z[i] = rhs[i] - t * z[i - 1];
    		if (alpha[i] == 0) {
      			status = 1;
    		}
  	}

  	/* backsubstitution */
  	x[N - 1] = z[N - 1] / alpha[N - 1];
  	if (N >= 2) {
    		for (i = N - 2, j = 0; j <= N - 2; j++, i--) {
      			x[i] = (z[i] - abovediag[i] * x[i + 1]) / alpha[i];
    		}
  	}

  	if (status == 1) {
    		std::cout << "Error : matrix must be positive definite!" << "\n";
  	}

  	return status;
}



std::vector<double> CrankNicolson(std::vector<double> u, std::vector<double> source, double alpha, double deltat){


	int N = u.size(); 
	std::vector<double> u_final(N);

	std::vector<double> rhs(N - 2, 0.);
	std::vector<double> diagonal(N - 2, 1. + 2. * alpha);
	std::vector<double> off_diagonal(N - 3, - alpha);
	std::vector<double> solution(N - 2, 0.);

	
	std::vector<std::vector<double>> rhs_matrix(N - 2, std::vector<double>(N - 2));

	for (int i = 1; i < N - 1; ++i) {
    		rhs[i - 1] = deltat * source[i] + alpha * u[i + 1] + (1. - 2. * alpha) * u[i] +  alpha * u[i - 1];
  	}	
	
	
	solve_tridiag_nonsym(diagonal, off_diagonal, off_diagonal, rhs, solution, diagonal.size());
		
	for (int i = 1; i < N - 1; ++i) u_final[i] = solution[i - 1];
  	return u_final;
}






int main(){
	for(int N : {pow(2,8), pow(2,9), pow(2,10)}){

		int time = 70;
		double deltat = 0.001, D = 0.1, H = 1.;
		double deltax = 2. * H / (double)(N-1); 	
		double alpha = D * deltat * 0.5 / pow(deltax, 2);
 
		std::vector<double> u(N, 0.);
		std::vector<double> x(N, 0.);	
		x = linspace(-1, 1, deltax);

		std::ofstream myfile;
		myfile.open("./pyplot/pde_" + std::to_string(N) + ".txt", std::ios::out);
	
		for(int i = 0; i < time/deltat;  i++){
			u = CrankNicolson(u, sourceTerm(D, x), alpha, deltat);
			if(i % 1000 == 0){
				myfile << i * deltat << "\t" << rms(x, u) << std::endl; 
				std::cout << i * 100 * deltat / time << "\% of events processed" << std::endl;
			}
		}
	
		myfile.close();	
	}
}
