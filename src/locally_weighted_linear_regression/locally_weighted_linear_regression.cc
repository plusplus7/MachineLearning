#include <cstdio>
#include <cmath>
#include <cstring>
#include "locally_weighted_linear_regression.h"

#define eps 1e-5
#define _TOW (1.0)
int LocallyWeightedLinearRegression::work_readfile(char *filename) {
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
  rate=0.001;
  return 0;
}
double LocallyWeightedLinearRegression::h_theta(double *_x, double *_t) {
  double res=0.0;
  for (int i=0; i<=n; i++) {
    res+=_x[i]*_t[i];
  }
  return res;
}
void LocallyWeightedLinearRegression::work(char *filename, double *input_x) {
  work_readfile(filename);
  qx=new double[n+1];
  qx[0]=1.0;
  for (int i=0; i<n; i++)
    qx[i+1]=input_x[i];
  get_weight();
  work_getanswer(input_x);
}
bool LocallyWeightedLinearRegression::check_convergence() {
  int i;
  for (i=0; i<=n; i++) {
    if (fabs(o_theta-theta) > eps)
      break;
  }
  return i == n;
}
void LocallyWeightedLinearRegression::show_result() {
  double res=0.0;
  for (int i=0; i<=n; i++) {
    res+=theta[i]*qx[i];
    printf("theta[%d]: %.6f\n",i,theta[i]);
  }
  printf("result: %.6f\n",res);
}
void LocallyWeightedLinearRegression::get_weight() {
  weight=new double[m];
  for (int i=0; i<m; i++) {
    double tmp=0.0;
    for (int j=0; j<=n; j++) {
      tmp+=(x[i][j]-qx[j])*(x[i][j]-qx[j]);
    }
    weight[i]=exp(-tmp/(2*_TOW*_TOW));
  }
}
bool LocallyWeightedLinearRegression::work_getanswer(double *input_x) {
  for (int round=0; round<100000 && !check_convergence(); round++) {
    memcpy(o_theta,theta,sizeof(theta));
    for (int i=0; i<=n; i++) {
      double sum_cost=0.0;
      for (int j=0; j<m; j++) {
        sum_cost+=weight[j]*(y[j]-h_theta(x[j],theta))*x[j][i];
      }
      theta[i]+=sum_cost*rate;
    }
  }
  return true;
}
void LocallyWeightedLinearRegression::work_clear() {
  for (int i=0; i<m; i++)
    delete [] x[i];
  delete [] x;
  delete [] y;
  delete [] weight;
  delete [] theta;
  delete [] o_theta;
  delete [] qx;
}
