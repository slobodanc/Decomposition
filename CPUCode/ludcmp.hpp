#include "nr3.hpp"

#ifndef LUDCMP_H
#define	LUDCMP_H

struct Kernel_IO {

	int		k;
	MatDoub* matrix;
	VecDoub* v;
	VecInt*	 indx;
	double* inputCoef;
	double* inputColumn;
	double*	outputRowNum;
	double* inputSubMatrix;
	double* outputSubMatrix;

	Kernel_IO(MatDoub*,VecDoub*,VecInt*,int);
	~Kernel_IO();
	void setInput();
	void setOutput();

};

//Object for solving linear equations A * x = b using LU decomposition, and related functions

struct LUdcmp
{
    Int n;
    MatDoub lu;                              //Stores the decomposition
    VecInt indx;                             //Stores the permutation
    Doub d;                                  //Used by determinant
    LUdcmp(MatDoub_I &a);                    //Constructor. Argument is the matrix A
    void solve(VecDoub_I &b, VecDoub_O &x);  //Solve for a single right-hand side
    void solve(MatDoub_I &b, MatDoub_O &x);  //Solve for multiple right-hand sides
    void inverse(MatDoub_O &ainv);           //Calculate matrix inverse
    Doub det();                              //return determinant of A
    void mprove(VecDoub_I &b, VecDoub_IO &x);
    MatDoub_I &aref;
};

#endif	/* LUDCMP_H */
