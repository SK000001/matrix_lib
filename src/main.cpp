#include "matrix.hpp"
using namespace std;

int main() {
    matrix *mat1 = new matrix(), *mat2 = new matrix();
    int r1, c1, r2, c2;

    /* MATRIX_1 CREATION */
    cout << "Enter rows for 1st matrix: "; cin >> r1;
    cout << endl << "Enter cols for 1st matrix: "; cin >> c1;
    mat1->createMatrix(r1, c1);
    cout << endl;

    /* MATRIX_2 CREATION */
    cout << endl << endl << "Enter rows for 2nd matrix: "; cin >> r2;
    cout << endl << "Enter cols for 2nd matrix: "; cin >> c2;
    mat2->createMatrix(r2, c2);
    cout << endl;

    /* PRINTING MATRIX_1 */
    cout << endl << endl << " #) 1st matrix: " << endl << endl;
    vector<float> mat = mat1->_matrix_();
    for (int i=0; i < mat1->size(); i++) {
        cout << mat[i] << " ";

        if ((i+1)%mat1->col() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    /* PRINTING MATRIX_2 */
    cout << endl << endl << " #) 2nd matrix: " << endl << endl;
    mat = mat2->_matrix_();
    for (int i=0; i < mat2->size(); i++) {
        cout << mat[i] << " ";

        if ((i+1)%mat2->col() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    /* MATRIX_1 TRANSPOSE */
    cout << endl << endl << " #) 1st matrix transpose: " << endl << endl;
    vector<float> trans = mat1->transpose();

    for (int i=0; i < mat1->size(); i++) {
        cout << trans[i] << " ";

        if ((i+1)%mat1->row() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    /* MATRIX_2 TRANSPOSE */
    cout << endl << endl << " #) 2nd matrix transpose: " << endl << endl;
    trans = mat2->transpose();;

    for (int i=0; i < mat2->size(); i++) {
        cout << trans[i] << " ";

        if ((i+1)%mat2->row() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    /* MATRIX_1 dot MATRIX_2 */
    cout << endl << endl << " #) 1st matrix dot 2nd matrix: " << endl << endl;
    vector<float> dot = mat1->dot(mat2);
    if (mat1->flag() != 1) {
        /* PRINTING MATRIX_1 dot MATRIX_2 */
        for (int i=0; i < mat1->row() * mat2->col(); i++) {
            cout << dot[i] << " ";

            if ((i+1)%mat1->row() == 0) {
                cout << endl;
            }
        }
    }
    cout << endl;

    /* MATRIX_2 dot MATRIX_1 */
    cout << endl << endl << " #) 2nd matrix dot 1st matrix: " << endl << endl;
    dot = mat2->dot(mat1);
    if (mat2->flag() != 1) {
        /* PRINTING MATRIX_1 dot MATRIX_2 */
        for (int i=0; i < mat2->row() * mat1->col(); i++) {
            cout << dot[i] << " ";

            if ((i+1)%mat2->row() == 0) {
                cout << endl;
            }
        }
    }
    cout << endl;

    /* MATRIX_1 + MATRIX_2 */
    cout << endl << endl << " #) 1st matrix + 2nd matrix: " << endl << endl;
    vector<float> sum = mat1->sum(mat2);

    for (int i=0; i < mat1->size(); i++) {
        cout << sum[i] << " ";

        if ((i+1)%mat1->col() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    /* MATRIX_1 - MATRIX_2 */
    cout << endl << endl << " #) 1st matrix - 2nd matrix: " << endl << endl;
    vector<float> diff = mat1->diff(mat2);

    for (int i=0; i < mat1->size(); i++) {
        cout << diff[i] << " ";

        if ((i+1)%mat1->col() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    /* MATRIX_2 - MATRIX_1 */
    cout << endl << endl << " #) 1st matrix - 2nd matrix: " << endl << endl;
    diff = mat2->diff(mat1);

    for (int i=0; i < mat1->size(); i++) {
        cout << diff[i] << " ";

        if ((i+1)%mat1->col() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}