#include "Maxfiles.h"
#include "nr3.hpp"
#include "ludcmp.hpp"

//TO DO: add CPU only execution and validate results

void generateInputData(MatDoub *input) {
	for (int i = 0; i < input->nrows(); i++){
		for (int j = 0; j < input->ncols(); j++)
			(*input)[i][j] = (double)(rand()%100);
	}
}

int main() {

	clock_t begin = clock();
	const int rank = 10;
	MatDoub matrix(rank,rank);
	generateInputData(&matrix);

	LUdcmp result(matrix);

	result.lu.print();
	clock_t end = clock();

	printf("Test done. Elapsed time: %f \n", (end - begin)/(double)CLOCKS_PER_SEC * 1000);

	return 0;
}


