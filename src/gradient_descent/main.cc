#include "batch_gradient_descent.h"
#include "stochastic_gradient_descent.h"

int main(int argc, char **argv)
{
  char data[]="../../data/gradient_descent_data.data";
  BatchGradientDescent *sgd=new BatchGradientDescent();
  //StochasticGradientDescent *sgd=new StochasticGradientDescent();
  sgd->work_start(data);
  sgd->work_getanswer();
  sgd->show_result();
  sgd->work_clear();
  delete sgd;
  return 0;
}
