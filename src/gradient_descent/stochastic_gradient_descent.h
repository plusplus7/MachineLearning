#ifndef MACHINELEARNING_GRADIENT_DESCENT_STOCHASTIC_GRADIENT_DESCENT_H_
#define MACHINELEARNING_GRADIENT_DESCENT_STOCHASTIC_GRADIENT_DESCENT_H
class StochasticGradientDescent
{
 public:
  StochasticGradientDescent();
  ~StochasticGradientDescent();
  int work_start(char *filename);
  bool work_getanswer();
  void show_result();
  bool check_convergence();
  void work_clear();
 protected:
 private:
  int m;    //the number of the training examples
  int n;    //the number of the features
  double **x;    //input features
  double *y;     //target variable
  double *theta; //parameters of the hypotheses
  double *o_theta;
  double rate;
  double h_theta(double *x, double *t);
};
#endif // end of  MACHINELEARNING_GRADIENT_DESCENT_STOCHASTIC_GRADIENT_DESCENT_H_
