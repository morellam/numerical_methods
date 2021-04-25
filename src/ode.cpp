#define _USE_MATH_DEFINES

#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;


double wrap(double x) { 
	if(x > 2*M_PI) x = x - (2*M_PI);
	else if(x < -2*M_PI) x = x + (2*M_PI);  
	return x;
	}


int main(){

	double steps[] = {0.01, 0.001, 0.0001};
	for(double t_step : steps){
	
		double time = 20;
		double k_1 = 0, k_2 = 0, k_3, k_4, j = 98.1;
		double x = 3.12, x_mid = 0, y = 0, y_mid = 0;
		double kinetic = 0, potential = 0, energy = 0;
	
		ofstream myfile;			
		myfile.open(".pyplot/ode_" + to_string(t_step) + ".txt", ios::out);
			for(double i = 0; i < time; i += t_step){
		
			k_1 = t_step * y;
			k_3 = - t_step * j * sin(x);
			x_mid = wrap(x + 0.5 * k_1);
			y_mid = y + 0.5 * k_3;

			k_2 = t_step * y_mid;
			x = wrap(x + k_2);
			k_4 = - t_step * j * sin(x_mid);
			y += k_4; 
		
			kinetic = 0.5 * pow(0.1,2) * pow(y,2);
			potential = 9.81 * 0.1 * (1 - cos(x));
			energy = kinetic + potential;
	
			if(i == t_step){
				myfile.close();	
				myfile.open("./pyplot/ode_" + to_string(t_step) + ".txt", ios::out);
			}
		
			myfile << i << "\t" << x << "\t" << y << "\t" << energy << endl;
		}

		myfile.close();
	}
}
