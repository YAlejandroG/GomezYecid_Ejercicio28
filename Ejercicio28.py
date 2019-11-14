import os
import numpy as np
import matplotlib.pyplot as plt

v0 = 22
teta = 34
g = 9.8
vx = v0*np.cos(teta*np.pi/180)
vy = v0*np.sin(teta*np.pi/180)
t = 2*vy/g

time = np.linspace(0,t,500)
xp = vx*time
yp = vy*time - g*time**2/2

proyectil = np.loadtxt("proyectil.dat")

plt.figure(figsize=(8,4))

x = proyectil[:,0]
y = proyectil[:,1]
plt.plot(x,y,c='b',label='With DRAG')
plt.plot(xp,yp,c='g',label='Without DRAG')

plt.grid()
plt.legend()

plt.savefig("proyectil.png")