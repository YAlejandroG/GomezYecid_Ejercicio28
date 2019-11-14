import os
import numpy as np
import matplotlib.pyplot as plt

proyectil = np.loadtxt("proyectil.dat")

plt.figure(figsize=(8,4))

x = proyectil[:,0]
y = proyectil[:,1]
plt.plot(x,y,label='With DRAG')

plt.savefig("proyectil.png")