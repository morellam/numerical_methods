import numpy as np
import matplotlib.pyplot as plt 

n, true_error, app_error = np.loadtxt('./pyplot/errors.txt', unpack = True)

plt.xlabel('N')
plt.xscale('log')
plt.ylabel('errors')
plt.yscale('log')

plt.plot(n, app_error, marker = 'o', c = 'b', label = 'approximate error')
plt.plot(n, true_error, marker = 'o', c = 'r', label = 'true error')
plt.legend(loc = 'upper right')

plt.savefig('./output/simpson.pdf')
