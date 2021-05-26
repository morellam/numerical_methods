#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;


double wrap(double x) { 
	if(x > 2*M_PI) x = x - (2*M_PI);
	else if(x < -2*M_PI) x = x + (2*M_PI);  
	return x;
}//end wrap




double rungekutta(double step, double time) {

	double m = 1, g = 9.81, l = 0.1;
	double k_1 = 0, k_2 = 0, k_3, k_4;
	double x = 3.12, x_mid = 0, y = 0, y_mid = 0;
	double kinetic = 0, potential = 0;

	ofstream myfile;
	myfile.open("./pyplot/ode_" + to_string(step) + ".txt", ios::out);
	
	for(double i = 0; i < time; i += step){
		k_1 = step * y;
		k_3 = - step * g / l * sin(x);
		x_mid = wrap(x + 0.5 * k_1);
		y_mid = y + 0.5 * k_3;

		k_2 = step * y_mid;
		x = wrap(x + k_2);
		k_4 = - step * g / l * sin(x_mid);
		y += k_4; 
	
		kinetic = 0.5 * m * pow(0.1,2) * pow(y,2);
		potential = m * g * l * (1 - cos(x));

		myfile << i << "\t" << x << "\t" << y << "\t" << kinetic + potential << endl;
	}

	myfile.close();

	return kinetic + potential;

}//end rungekutta	





int main(){

	double time = 20;

	double steps[] = {0.01, 0.001, 0.0001};

	for(double t_step : steps){
		 rungekutta(t_step, time);	
	}

}//end main






