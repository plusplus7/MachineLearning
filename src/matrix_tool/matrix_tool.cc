#include <cstdio>
#include <cstring>
#include <iostream>
#include "matrix_tool.h"
namespace matrixtool {
Matrix::Matrix() {
	p_mat=NULL;
	n_row=0;
	n_column=0;
}
/**
 * type 1 means producing a int-type matrix
 * type 2 means producing a double-typematrix
*/
Matrix::Matrix(int row, int col) {
	n_row=row;
	n_column=col;
	p_mat=new double *[n_row];
	for (int i=0; i<n_row;  i++) {
		p_mat[i]=new double [n_column];
	}
}
Matrix::Matrix(int row, int col, double *t_mat) {
	n_row=row;
	n_column=col;
	p_mat=new double *[n_row];
	for (int i=0; i<n_row;  i++) {
		p_mat[i]=new double [n_column];
		for (int j=0; j<n_column; j++) {
			p_mat[i][j]=*(t_mat+i*n_column+j);
		}
	}
}
Matrix::~Matrix() { 
	if (p_mat != NULL) {
		for (int i=0; i<n_row; i++)
			delete [] p_mat[i];
		delete [] p_mat;
	}
}
void Matrix::show_matrix() {
	std::cout<<n_row<<" "<<n_column<<std::endl;
	for (int i=0; i<n_row; i++) { 
		for (int j=0; j<n_column; j++) {
			std::cout<<p_mat[i][j]<<std::endl;	
		}
	}
}
}
