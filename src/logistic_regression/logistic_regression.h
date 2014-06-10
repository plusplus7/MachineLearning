#ifndef MACHINELEARNING_LOGISTIC_REGRESSION_LOGISTIC_REGRESSION_
#define MACHINELEARNING_LOGISTIC_REGRESSION_LOGISTIC_REGRESSION_

class LogisticRegression {
 public:
	 void work(char *filaname);
	 void show_result();
 protected:
 private:
	 double *theta;
	 double *o_theta;
	 double **x;
	 double *y;
	 int m;
	 int n;
	 double learning_rate;
	
	 bool check_convergence();
	 double h_theta(double *t,double *x);
	 void read_data(char *filename);
};
#endif // end of  MACHINELEARNING_LOGISTIC_REGRESSION_LOGISTIC_REGRESSION_

