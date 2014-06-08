#include "matrix_tool.h"
#include <iostream>
int main()
{
	using matrixtool::Matrix;
	double a[3][2]={1,2,3,4,5,6};
	Matrix *m;
	m=new Matrix(3,2,(double *)a);
	m->show_matrix();
	m->transpose();
	m->show_matrix();

	delete m;
	return 0;
}
