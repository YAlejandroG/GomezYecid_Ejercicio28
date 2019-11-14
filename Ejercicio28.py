import os
import numpy as np
import matplotlib.pyplot as plt

proyectil = np.loadtxt("proyectil.dat")
proyectilSF = np.loadtxt("proyectilSF.dat")

plt.figure(figsize=(8,4))

x = proyectil[:,0]
y = proyectil[:,1]

xp = proyectilSF[:,0]
yp = proyectilSF[:,1]

plt.plot(x,y,c='orange',label='With DRAG')
plt.plot(xp,yp,c='g',label='Without DRAG')

plt.grid()
plt.legend()

plt.savefig("proyectil.png")