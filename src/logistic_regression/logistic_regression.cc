#include "logistic_regression.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define eps 1e-6
void LogisticRegression::read_data(char *filename) {
	FILE *fp=fopen(filename,"r");
	fscanf(fp,"%d%d",&m,&n);
	y=new double [m];
	x=new double *[m];
	theta=new double [n+1];
	o_theta=new double [n+1];
	learning_rate=0.001;
	for (int i=0; i<m; i++) {
		x[i]=new double [n+1];
		x[i][0]=1.0;
		fscanf(fp,"%lf%lf%lf",x[i]+1,x[i]+2,y+i);
	}
	for (int i=0; i<=n; i++) {
		theta[i]=0.0;
		o_theta[i]=100.0;
	}
}
bool LogisticRegression::check_convergence() {
	int i;
	for (i=0; i<=n; i++) {
		if (fabs(o_theta[i]-theta[i]) > eps)
			break;
	}
	return i == n+1;
}
void LogisticRegression::work(char *filename) {
	read_data(filename);
	//Stochastic gradient acscent
	for (int round=0; round<=100000 && !check_convergence(); round++) {
		memcpy(o_theta,theta,sizeof(double)*(n+1));
		for (int i=0; i<m; i++) {
			for (int j=0; j<=n; j++) {
				theta[j]+=learning_rate*(y[i]-h_theta(theta, x[i]))*x[i][j];
			}
		}
	}
}
double LogisticRegression::h_theta(double *t, double *v) {
	double res=0.0;
	for (int i=0; i<=n; i++) {
		res+=theta[i]*v[i];
	}
	return (1/(1+exp(-res)));
}
void LogisticRegression::show_result() {
	for (int i=0; i<=n; i++) {
		printf("theta %d: %.4f\n",i,theta[i]);
	}
}

