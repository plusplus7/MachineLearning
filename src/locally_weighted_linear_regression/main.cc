#include "locally_weighted_linear_regression.h"
int main(int argc, char **argv) {
  char dir[]="../../data/gradient_descent_data.data";
  double input_x[]={8.0,3.0};
  LocallyWeightedLinearRegression *lwr=new LocallyWeightedLinearRegression();  
  lwr->work(dir,input_x);
  lwr->show_result();
  lwr->work_clear();
  delete lwr;
  return 0;
}  
