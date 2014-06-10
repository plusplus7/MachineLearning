#include <cstdio>
#include <cmath>
#include <cstring>
#include "stochastic_gradient_descent.h"
#define eps 1e-13
StochasticGradientDescent::StochasticGradientDescent() {
  m=0;
  n=0;
  x=NULL;
  y=NULL;
  theta=NULL;
  rate=0.001;
}
StochasticGradientDescent::~StochasticGradientDescent() {}
int StochasticGradientDescent::work_start(char *filename) {
  FILE *fp=fopen(filename,"r");
  if ( fp == NULL )
    return -1;
  fscanf(fp,"%d%d",&m,&n);  
  x=new double *[m];
  y=new double [m];
  theta=new double [n+1];
  o_theta=new double [n+1];
  for (int i=0; i<m; i++) {
    x[i]=new double [n+1];
    x[i][0]=1.0;
    for (int j=1; j<=n; j++) {
      fscanf(fp,"%lf",x[i]+j);
    }
  }
  for (int i=0; i<m; i++) { 
    fscanf(fp,"%lf",y+i);
  }
  for (int i=0; i<=n; i++) {
    theta[i]=0.0;
    o_theta[i]=100.0;
  }
  return 0;
}
bool StochasticGradientDescent::check_convergence() {
  int i;
  for (i=0; i<=n; i++) {
    if (fabs(o_theta[i]-theta[i]) > eps)
      break;
  }
  return i == n+1;
}
bool StochasticGradientDescent::work_getanswer() {
  for (int round=0; round<100000 && !check_convergence(); round++) {
	memcpy(o_theta,theta,sizeof(double)*(n+1));
    for (int i=0; i<m; i++) {
      for (int j=0; j<=n; j++) {
        theta[j]+=rate*(y[i]-h_theta(x[i],theta))*x[i][j];
      }
    }
  }
  return true;
}
double StochasticGradientDescent::h_theta(double *x, double *t) {
  double res=0.0;
  for (int i=0; i<=n; i++) {
    res+=x[i]*theta[i];
  }
  return res;
}
void StochasticGradientDescent::show_result() {
  for (int i=0; i<=n; i++) {
    printf("theta %d: %.6f\n", i, theta[i]);
  }
  for (int i=0; i<m; i++) {
    printf("h_theta %d: %.6f\n", i, y[i]-h_theta(x[i],theta));
  }
}
void StochasticGradientDescent::work_clear() {
  for (int i=0; i<m; i++)
    delete [] x[i];
  delete [] x;
  delete [] y;
  delete [] theta;
  delete [] o_theta;
}
