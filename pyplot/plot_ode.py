import numpy as np
import matplotlib.pyplot as plt 

path = './pyplot/'
files = {path + 'ode_0.010000.txt', path + 'ode_0.001000.txt', path + 'ode_0.000100.txt'}

for f in files:
	time, theta, omega, energy = np.loadtxt(f, unpack = True)
	
	fig, axis = plt.subplots(3);
	fig.suptitle(str(f));
	axis[0].set_ylabel(r'$\theta$ ' ' [rad]')
	axis[0].plot(time, theta, marker = ',', c = 'b')
	axis[1].set_ylabel(r'$\omega$ ' ' [rad/s]')
	axis[1].plot(time, omega, marker = ',', c = 'r')
	axis[2].set_xlabel('time ' ' [s]')
	axis[2].set_ylabel(r'E$_{tot}$ ' ' [J]');
	axis[2].plot(time, energy, marker = ',', c = 'g')
	axis[2].plot(time, np.full(time.size, energy[0]), marker = ',', c = 'orange')
	axis[2].set_ylim(1.95, 1.99)	
	plt.show()

