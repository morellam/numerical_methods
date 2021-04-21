import numpy as np
import matplotlib.pyplot as plt 

path = './pyplot/'
files = {path + 'ode_0.010000.txt', path + 'ode_0.010000.txt', path + 'ode_0.000100.txt'}

for f in files:
	time, theta, omega, energy = np.loadtxt(f, unpack = True)
	fig, axis = plt.subplots(3);
	axis[0].set_title('theta')
	axis[0].plot(time, theta, marker = '.', c = 'b')
	axis[1].set_title('omega')
	axis[1].plot(time, omega, marker = '.', c = 'r')
	axis[2].set_title('total energy');
	axis[2].plot(time, energy, marker = '.', c = 'g')
	plt.show()

