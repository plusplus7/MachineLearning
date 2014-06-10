#include <cstdio>
#include <cmath>
#include <cstring>
#include "batch_gradient_descent.h"
#define eps 1e-8
BatchGradientDescent::BatchGradientDescent() {
  m=0;
  n=0;
  x=NULL;
  y=NULL;
  theta=NULL;
  rate=0.001;
}
BatchGradientDescent::~BatchGradientDescent() {}
int BatchGradientDescent::work_start(char *filename) {
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
bool BatchGradientDescent::check_convergence() {
  int i;
  for (i=0; i<=n; i++) {
    if (fabs(o_theta[i]-theta[i]) > eps)
      break;
  }
  return i == n;
}
bool BatchGradientDescent::work_getanswer() {
  for (int round=0; round<100000 && !check_convergence(); round++) {
    memcpy(o_theta,theta,sizeof(theta));
    for (int i=0; i<=n; i++) {
      double sum_cost=0.0;
      for (int j=0; j<m; j++) {
        sum_cost+=(y[j]-h_theta(x[j],theta))*x[j][i];
      }
      theta[i]+=sum_cost*rate;
    }
  }
  return true;
}
double BatchGradientDescent::h_theta(double *x, double *t) {
  double res=0.0;
  for (int i=0; i<=n; i++) {
    res+=x[i]*theta[i];
  }
  return res;
}
void BatchGradientDescent::show_result() {
  for (int i=0; i<=n; i++) {
    printf("theta %d: %.6f\n", i, theta[i]);
  }
  for (int i=0; i<m; i++) {
    printf("h_theta %d: %.6f\n", i, y[i]-h_theta(x[i],theta));
  }
}
void BatchGradientDescent::work_clear() {
  for (int i=0; i<m; i++)
    delete [] x[i];
  delete [] x;
  delete [] y;
  delete [] theta;
  delete [] o_theta;
}
