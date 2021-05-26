import numpy as np
import matplotlib.pyplot as plt


 
plt.xlabel("time")
plt.ylabel("Rms")
plt.yscale("log")

directory = './pyplot/'
colors = ['r', 'g', 'b']
N = ['256', '512', '1024']
for n, col  in zip(N, colors):
	time, rms = np.loadtxt(directory + 'pde_' + n + '.txt', unpack = True)
	plt.plot(time, rms, marker = ".",linestyle = "none", c = col)


plt.legend([r'$2^8$', r'$2^9$', r'$2^{10}$'])
plt.savefig('./output/pde_rms.pdf');


