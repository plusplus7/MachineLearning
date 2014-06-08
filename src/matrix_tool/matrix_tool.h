/**
 * A matrix tool
 */
#ifndef MACHINELEARNING_MATRIX_TOOL_MATRIX_TOOL_ 
#define MACHINELEARNING_MATRIX_TOOL_MATRIX_TOOL_ 
namespace matrixtool {
class Matrix
{
public:
 Matrix();
 Matrix(int row, int col);
 Matrix(int row, int col, double *t_mat);
 ~Matrix();
 void transpose();
 void show_matrix();
protected:
private:
 double **p_mat;
 int n_row;
 int n_column;
};
}
#endif // end of MACHINELEARNING_MATRIX_TOOL_MATRIX_TOOL_ 
