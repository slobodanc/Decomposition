#include "Decomposition.h"
#include "ludcmp.hpp"

#define allignment 16 // PCI allignment

Kernel_IO::Kernel_IO(MatDoub *mm, VecDoub *vv, VecInt* ii, int kk) : k(kk), matrix(mm), v(vv), indx(ii) {
	int rank, addr, padding;
	rank = matrix->nrows();
	addr = 0;
	padding = (k * k % 2) ? (allignment - ((k * k * sizeof(double))
			% allignment)) / sizeof(double) : 0;
	inputColumn = new double[k + padding];
	inputCoef = new double[k + padding];
	outputRowNum = new double[allignment / sizeof(double)];
	inputSubMatrix = new double[k * k + padding];
	outputSubMatrix = new double[k * k + padding];
	for (int i = rank - k; i < rank; i++, addr++) {
		inputColumn[addr] = abs((*matrix)[i][rank - k]);
		inputCoef[addr] = (*v)[i];
	}
}

void Kernel_IO::setInput() {
	int rank, addr, imax;
	imax = (int) outputRowNum[1];
	rank = matrix->nrows();
	addr = 0;
	if (imax != 0) {
		for (int i = 0; i < rank; i++) {
			double temp = (*matrix)[rank - k + imax][i];
			(*matrix)[rank - k + imax][i] = (*matrix)[rank - k][i];
			(*matrix)[rank - k][i] = temp;
		}
		(*v)[imax] = (*v)[rank - k]; //check
	}
	for (int i = rank - k; i < rank; i++)
		for (int j = rank - k; j < rank; j++)
			inputSubMatrix[addr++] = (*matrix)[i][j];
	//indx[rank-k] = imax; //check
	//if (lu[k][k] == 0.0) lu[k][k] = TINY;
}

void Kernel_IO::setOutput() {

	int rank, addr;
	rank = matrix->nrows();
	addr = 0;
	for (int i = rank - k; i < rank; i++)
			for (int j = rank - k; j < rank; j++)
				(*matrix)[i][j] = outputSubMatrix[addr++];

}

Kernel_IO::~Kernel_IO() {
	delete[] inputCoef;
	delete[] inputSubMatrix;
	delete[] outputSubMatrix;
	delete[] inputColumn;
	delete[] outputRowNum;
}

LUdcmp::LUdcmp(MatDoub_I &a) :
	n(a.nrows()), lu(a), aref(a), indx(n) {
	const Doub TINY = 1.0e-40;
	Int i, imax, j, k;
	Doub big, temp;
	VecDoub vv(n);
	Kernel_IO *data;
	d = 1.0;
	for (i = 0; i < n; i++) {
		big = 0.0;
		for (j = 0; j < n; j++)
			if ((temp = abs(lu[i][j])) > big)
				big = temp;
		if (big == 0.0)
			throw("Singular matrix in LUdcmp");
		vv[i] = 1.0 / big;
	}

	for (k = 0; k < n; k++) {

		data = new Kernel_IO(&lu,&vv,&indx,n-k);
		Decomposition_firstKernel(data->k,data->inputColumn,data->inputCoef,data->outputRowNum);
		data->setInput();
		Decomposition_secondKernel(data->k,data->inputSubMatrix,data->outputSubMatrix);
		data->setOutput();

	}
}
void LUdcmp::solve(VecDoub_I &b, VecDoub_O &x) {
	Int i, ii = 0, ip, j;
	Doub sum;
	if (b.size() != n || x.size() != n)
		throw("LUdcmp::solve bad sizes");
	for (i = 0; i < n; i++)
		x[i] = b[i];
	for (i = 0; i < n; i++) {
		ip = indx[i];
		sum = x[ip];
		x[ip] = x[i];
		if (ii != 0)
			for (j = ii - 1; j < i; j++)
				sum -= lu[i][j] * x[j];
		else if (sum != 0.0)
			ii = i + 1;
		x[i] = sum;
	}
	for (i = n - 1; i >= 0; i--) {
		sum = x[i];
		for (j = i + 1; j < n; j++)
			sum -= lu[i][j] * x[j];
		x[i] = sum / lu[i][i];
	}
}

void LUdcmp::solve(MatDoub_I &b, MatDoub_O &x) {
	int i, j, m = b.ncols();
	if (b.nrows() != n || x.nrows() != n || b.ncols() != x.ncols())
		throw("LUdcmp::solve bad sizes");
	VecDoub xx(n);
	for (j = 0; j < m; j++) {
		for (i = 0; i < n; i++)
			xx[i] = b[i][j];
		solve(xx, xx);
		for (i = 0; i < n; i++)
			x[i][j] = xx[i];
	}
}
void LUdcmp::inverse(MatDoub_O &ainv) {
	Int i, j;
	ainv.resize(n, n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			ainv[i][j] = 0.;
		ainv[i][i] = 1.;
	}
	solve(ainv, ainv);
}
Doub LUdcmp::det() {
	Doub dd = d;
	for (Int i = 0; i < n; i++)
		dd *= lu[i][i];
	return dd;
}
void LUdcmp::mprove(VecDoub_I &b, VecDoub_IO &x) {
	Int i, j;
	VecDoub r(n);
	for (i = 0; i < n; i++) {
		Ldoub sdp = -b[i];
		for (j = 0; j < n; j++)
			sdp += (Ldoub) aref[i][j] * (Ldoub) x[j];
		r[i] = sdp;
	}
	solve(r, r);
	for (i = 0; i < n; i++)
		x[i] -= r[i];
}
