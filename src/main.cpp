#include "matrix.hpp"

int main() {
    matrix *mat1 = new matrix();
    mat1->createMatrix(2,3);
    vector<float> mat = mat1->_matrix_();

    for (int i=0; i < mat1->size(); i++) {
        cout << mat[i] << " ";

        if ((i+1)%mat1->row() == 0) {
            cout << endl;
        }
    }

    cout << endl;
    mat1->transpose();
    vector<float> trans = mat1->_matrix_();

    for (int i=0; i < mat1->size(); i++) {
        cout << trans[i] << " ";

        if ((i+1)%mat1->col() == 0) {
            cout << endl;
        }
    }
    cout << endl;

    vector<float> dot = mat1->dot(mat1->_matrix_(), 3, 2);

    for (int i=0; i < 4; i++) {
        cout << dot[i] << " ";

        if ((i+1)%mat1->row() == 0) {
            cout << endl;
        }
    }

    return 0;
}