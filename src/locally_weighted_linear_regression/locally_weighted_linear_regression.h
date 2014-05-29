#ifndef MACHINE_LEARNING_LOCALLY_WEIGHTED_LINEAR_REGRESSION_
#define MACHINE_LEARNING_LOCALLY_WEIGHTED_LINEAR_REGRESSION_
class LocallyWeightedLinearRegression
{
 public:
  void work(char *filename,double *input_x);
  void work_clear();
  void show_result();
 protected:
 private:
  int m;    //the number of the training examples
  int n;    //the number of the features
  double **x;    //input features
  double *qx;
  double *y;     //target variable
  double *theta; //parameters of the hypotheses
  double *o_theta;
  double rate;
  double *weight;

  double h_theta(double *x, double *t);
  bool check_convergence();
  void get_weight();
  bool work_getanswer(double *input_x);
  int work_readfile(char *filename);
};
#endif// end of  MACHINE_LEARNING_LOCALLY_WEIGHTED_LINEAR_REGRESSION_
