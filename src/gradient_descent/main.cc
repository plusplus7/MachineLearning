#include "batch_gradient_descent.h"
int main(int argc, char **argv)
{
  char data[]="../../data/gradient_descent_data.data";
  BatchGradientDescent *bgd=new BatchGradientDescent();
  bgd->work_start(data);
  bgd->work_getanswer();
  bgd->show_result();
  bgd->work_clear();
  delete bgd;
  return 0;
}
