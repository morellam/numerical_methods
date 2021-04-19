#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

inline double f(double x) { return pow(x,4)-2*x+1; }


double simpson(double x(double y), double a, double b, double n){
	double integral = 0;
	double h = (b-a)/n;
	double sum = x(a)+x(b); 
        
	for(int i = 1; i < n; i++){
		if(i % 2 == 0) sum += 2 * x(a + i*h);
		else 	       sum += 4 * x(a + i*h);
	}
	
	return integral = sum*h/3;
}


int main(){

	double integral1 = 0, integral2 = 0;
     	double true_error = 0, approx_error = 0;

	double division[] = {1e2, 1e3, 1e4, 1e5, 1e6, 1e7};
	
	ofstream myfile;
	myfile.open("pyplot/errors.txt", ios::out);

	
	for(double i : division){
		integral1 = simpson(f,0,2,i);
		integral2 = simpson(f,0,2,2*i);
		approx_error = abs(integral2 - integral1)/15.0;
		
		true_error = 1.6/3.0 * pow(2.0/i, 4);
		
		myfile << i << "\t" << true_error  << "\t" << approx_error << endl;	
	}
	
	myfile.close();
      

}
