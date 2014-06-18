#include "k_NN.h"
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
bool k_NN::train(char *filename, int data_num, int feature_num, int label_num) {
	
	m=data_num;
	n=feature_num;
	// Read dataset from the file
	FILE *fp=fopen(filename, "r");

	max_values=new double [n];
	min_values=new double [n];

	trainset_input=new double *[m];
	trainset_output=new int [m];
	for (int i=0; i<m; i++) {
		trainset_input[i]=new double [n];
		for (int j=0; j<n; j++) {
			fscanf(fp,"%lf", trainset_input[i]+j);
			max_values[j]=(i==0)?trainset_input[i][j]:(trainset_input[i][j]>max_values[j]?trainset_input[i][j]:max_values[j]);
			min_values[j]=(i==0)?trainset_input[i][j]:(trainset_input[i][j]<min_values[j]?trainset_input[i][j]:min_values[j]);
		}
		char tmp[20];
		fscanf(fp, "%s", tmp);
		if (tmp[0] == 'd')
			trainset_output[i]=0;
		else if (tmp[0] == 's')
			trainset_output[i]=1;
		else if (tmp[0] == 'l')
			trainset_output[i]=2;
		
	}
	// Start to normalize the data
	for (int i=0; i<n; i++) 
		max_values[i]-=min_values[i];
	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			trainset_input[i][j]=(trainset_input[i][j]-min_values[j])/max_values[j];
		}
	}
	// Pretty cool, hum!
	fclose(fp);
}

int k_NN::classify(double *x, int k) {
	struct T {
		double dist;
		int type;
		T(double d=0,int t=0):dist(d),type(t) {}
		bool operator < (const T &t) const {
			return dist<t.dist;
		}
	};
	using std::vector;
	using std::sort;
	vector<T> vt;
	vt.clear();
	for (int i=0; i<n; i++) {
		x[i]=(x[i]-min_values[i])/max_values[i];
	}
	for (int i=0; i<m; i++) {
		double dist=get_dist(trainset_input[i],x);
		vt.push_back(T(dist,trainset_output[i]));
	}
	sort(vt.begin(),vt.end());

	int *res=new int [n];
	memset(res,0,sizeof(int)*n);
	for (int i=0; i<k; i++) {
		res[vt[i].type]++;
	}
	int cnt=0,ans;
	for (int i=0; i<n; i++) {
		if (res[i] > cnt)
			cnt=res[i],ans=i;
	}
	
	delete res;
	return ans;
}
double k_NN::get_dist(double *a,double *b) {
	double res=0.0;
	for (int i=0; i<n; i++) {
		double tmp=a[i]-b[i];
		res+=tmp*tmp;
	}
	return sqrt(res);
}
void k_NN::clear() {
	for (int i=0; i<m; i++) {
		delete [] trainset_input[i];
	}
	delete trainset_input;
	delete trainset_output;
	delete max_values;
	delete min_values;
}
