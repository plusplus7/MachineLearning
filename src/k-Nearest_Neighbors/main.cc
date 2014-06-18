#include "k_NN.h"
#include <iostream>
int main() {
	double x[3]={40999,9.161978,1.110180};
	k_NN *knn=new k_NN();
	knn->train("../../data/k-NN_data.data",900,3,3);
	
	std::cout<<"Training finished!"<<std::endl;
	FILE *fp=fopen("../../data/k-NN_test_data.data","r");
	int right=0,all=0;
	while (!feof(fp)) {
		char tmp[20];
		int t;
		fscanf(fp,"%lf%lf%lf",x+0,x+1,x+2);
		fscanf(fp,"%s",tmp);
		if (tmp[0] == 'd') t=0;
		else if (tmp[0] == 's') t=1;
		else if (tmp[0] == 'l') t=2;
		int ans=knn->classify(x,19);
		if (ans == t)
			right++;
		all++;
		std::cout<<"The k-NN result: "<<ans<<" "<<"while answer is "<<t<<std::endl;
	}
	std::cout<<"The accuracy is "<<(double)right/all<<std::endl;
	knn->clear();
	delete knn;
	return 0;
}
