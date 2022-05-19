#include <iostream>
using namespace std;

/********************************************************************************************************************/
/*                                                                                                                  */
/*                                                  DOT PRODUCT                                                     */
/*                                                                                                                  */
/********************************************************************************************************************/
/* NOTES:                                                                                                           */
/*    >  format of *sizes = [ row of mat_1  ,  col of mat_1  ,  row of mat_2  ,  col of mat_2 ]                     */
/*                                                                                                                  */
/********************************************************************************************************************/

double* dot_prd(int *sizes, double *mat_1, double *mat_2) {
    if (sizes[1] != sizes[2]) { cout << ">> ERROR: invalid sizes for dot product." << endl; return nullptr; }

    static double *dot = (double*)malloc(sizes[0]*sizes[3]*sizeof(double));
    int count = 0;

    for (int x=0; x < sizes[0]; x++) { // row of mat_1
        for (int y=0; y < sizes[3]; y++) { // col of mat_2
            double sum=0;
            for (int z=0; z < sizes[1]; z++) { // col of mat_1
                sum += *(mat_1 + ((x * sizes[1]) + z)) * *(mat_2 + ((z * sizes[3]) + y));
            }
            *(dot + count++) = sum;
        }
    }

    return dot;
}

/********************************************************************************************************************/
/*                                                                                                                  */
/*                                                  CROSS MULTIPLICATION                                            */
/*                                                                                                                  */
/********************************************************************************************************************/

double* cross_mult(int *sizes, double *mat_1, double *mat_2) {
    if ((sizes[0] != sizes[2]) || (sizes[1] != sizes[3])) { cout << "ERROR: invalid sizes for cross product" << endl; return nullptr; }

    static double *mult = (double*)malloc(sizes[0]*sizes[1]*sizeof(double));

    for (int i=0; i < sizes[0] * sizes[1]; i++) {
        *(mult+i) =  *(mat_1+i) * *(mat_2+i);
    }

    return mult;
}

/********************************************************************************************************************/
/*                                                                                                                  */
/*                                                  PRINT OUT THE MATRIX                                            */
/*                                                                                                                  */
/********************************************************************************************************************/

void print_matrices(double* mat, int r, int c) {
    setfill(' ');
    for (int i=0; i < r * c; ++i) {
        cout << left << setw(15) << *(mat+i);

        if ((i+1) % c == 0) { cout << endl; }
    }
}