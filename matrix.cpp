#include <iostream>
#include <iomanip>
#include "matrix.h"

#ifdef _WIN32
	char cls[4] = "cls";
#else
	char cls[6] = "clear";
#endif

using namespace std;

int main() {
    system("clear");

    int r1, c1, r2, c2;

    // initializing sizes
    cout << endl << ">> Enter rows for first array: "; cin >> r1;
    cout << endl << ">> Enter columns for first array: "; cin >> c1;
    cout << endl << ">> Enter rows for second array: "; cin >> r2;
    cout << endl << ">> Enter columns for second array: "; cin >> c2;

    int sizes[4] = { r1, c1, r2, c2 };

    // initializing mat_1
    double x = 1;

    double *mat_1 = (double*)malloc(sizeof(double) * r1 * c1);
    for (int i=0, r=0, c=0; i < r1 * c1; ++i, ++c) {
        *(mat_1 + i) = x++;

        if ((c+1) % c1 == 0) { r++; c = -1; }
    }

    // printing mat_1
    cout << endl << endl << " #) 1st matrix: " << endl << endl;
    print_matrices(mat_1, r1, c1);

    // initializing mat_2

    double *mat_2 = (double*)malloc(sizeof(double) * r2 * c2);
    for (int i=0, r=0, c=0; i < r2 * c2; ++i, ++c) {
        *(mat_2 + i) = --x;

        if ((c+1) % c2 == 0) { r++; c = -1; }
    }

    // printing mat_2
    cout << endl << "#) 2nd matrix: " << endl << endl;
    print_matrices(mat_2, r2, c2);

    // dot product
    cout << endl << "#) dot matrix: " << endl << endl;
    double *dot = dot_prd(&sizes[0], mat_1, mat_2);
    if ( dot != NULL ) { print_matrices(dot, r1, c2); }
    free(dot);

    // cross multiplication
    cout << endl << "#) cross mult matrix: " << endl << endl;
    double *mult = cross_mult(&sizes[0], mat_1, mat_2);
    if ( mult != NULL ) { print_matrices(mult, r1, c1); }
    free(mult);

    // transpose of mat_1
    cout << endl << "#) transpose of mat_1: " << endl << endl;
    double *T1 = transpose(mat_1, r1, c1);
    if ( T1 != NULL ) { print_matrices(T1, c1, r1); }
    free(T1);

    // transpose of mat_2
    cout << endl << "#) transpose of mat_2: " << endl << endl;
    double *T2 = transpose(mat_2, r2, c2);
    if ( T2 != NULL ) { print_matrices(T2, c2, r2); }
    free(T2);

    // addiition of mat_1 and mat_2
    cout << endl << "#) addition of mat_1 and mat_2: " << endl << endl;
    double *add = matrix_add(sizes, mat_1, mat_2);
    if ( add != NULL ) { print_matrices(add, r1, c1); }
    free(add);

    // subtraction of mat_1 and mat_2
    cout << endl << "#) subtraction of mat_1 and mat_2: " << endl << endl;
    double *sub = matrix_sub(sizes, mat_1, mat_2);
    if ( sub != NULL ) { print_matrices(sub, r1, c1); }
    free(sub);

    // division of mat_1 by mat_2
    cout << endl << "#) division of mat_1 by mat_2: " << endl << endl;
    double *div = matrix_div(sizes, mat_1, mat_2);
    if ( div != NULL ) { print_matrices(div, r1, c1); }
    free(div);

    free(mat_1); free(mat_2);
    
    return 0;
}