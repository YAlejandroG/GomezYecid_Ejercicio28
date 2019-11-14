#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

double v0 = 22.0;
double teta = 34.0;
double g = 9.8;
double Kf = 0.9;
double dt = 0.01;

double fx(double t, double x, double vx); 
double fy(double t, double y, double vy); 
double fdx(double t, double x, double vx, double v, double n); 
double fdy(double t, double y, double vy, double v, double n); 
int rk4(double t, double dt, double n, double & x, double & vx, double & y, double & vy); 

int main(void)
{
  double x, y, vx, vy, time, n, t;
  n = 1.0;
  x = 0.0;
  y = 0.0;
  vx = v0*cos(teta*M_PI/180.0);
  vy = v0*sin(teta*M_PI/180.0);
  t = 2.0*vy/g;
    
  ofstream outfile;
  outfile.open("proyectil.dat");
    
  for(time = 0; time <= t; time += dt) {
    outfile << x << "\t" << y << endl;
    rk4(time, dt, n, x, vx, y, vy);
  }
  outfile.close();
    
  return 0;
}

double fx(double t, double x, double vx)
{
  return vx;
}

double fy(double t, double y, double vy)
{
  return vy;
}

double fdx(double t, double x, double vx, double v, double n)
{
  return -Kf*pow(vx, n)*vx/v;
}

double fdy(double t, double y, double vy, double v, double n)
{
  return -g-Kf*pow(vy, n)*vy/v;
}

int rk4(double t, double dt, double n, double & x, double & vx, double & y, double & vy) 
{
  double v = sqrt(pow(vx,2)+pow(vy,2));

  double k10x, k11x, k20x, k21x, k30x, k31x, k40x, k41x;
  k10x = dt*fx(t, x, vx);
  k11x = dt*fdx(t, x, vx, v, n);
  k20x = dt*fx(t+dt/2, x + k10x/2, vx + k11x/2);
  k21x = dt*fdx(t+dt/2, x + k10x/2, vx + k11x/2, v, n);
  k30x = dt*fx(t+dt/2, x + k20x/2, vx + k21x/2);
  k31x = dt*fdx(t+dt/2, x + k20x/2, vx + k21x/2, v, n);
  k40x = dt*fx(t+dt, x + k30x, vx + k31x);
  k41x = dt*fdx(t+dt, x + k30x, vx + k31x, v, n);

  x = x + (1.0/6.0)*(k10x + 2*k20x + 2*k30x + k40x);
  vx = vx + (1.0/6.0)*(k11x + 2*k21x + 2*k31x + k41x);
    
  double k10y, k11y, k20y, k21y, k30y, k31y, k40y, k41y;
  k10y = dt*fy(t, y, vy);
  k11y = dt*fdy(t, y, vy, v, n);
  k20y = dt*fy(t+dt/2, y + k10y/2, vy + k11y/2);
  k21y = dt*fdy(t+dt/2, y + k10y/2, vy + k11y/2, v, n);
  k30y = dt*fy(t+dt/2, y + k20y/2, vy + k21y/2);
  k31y = dt*fdy(t+dt/2, y + k20y/2, vy + k21y/2, v, n);
  k40y = dt*fy(t+dt, y + k30y, vy + k31y);
  k41y = dt*fdy(t+dt, y + k30y, vy + k31y, v, n);

  y = y + (1.0/6.0)*(k10y + 2*k20y + 2*k30y + k40y);
  vy = vy + (1.0/6.0)*(k11y + 2*k21y + 2*k31y + k41y);
    
  return 0;
}