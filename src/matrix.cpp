#include "matrix.hpp"
using namespace std;

// matrix::matrix() {}
// matrix::~matrix() {}

vector<float> matrix::createMatrix(int r, int c) {
    _row = r;
    _col = c;
    _size = r*c;
    
    vector <float> mat(_size);

    for (int i=0; i < _size; i++) {
        cout << endl << "Enter " << i+1 << "th element: ";
        cin >> mat[i];
    }

    _matrix = mat;
    return mat;
}

vector<float> matrix::transpose() {
    vector<float> T(_size);

    for (int i=0; i < _col; i++) {
        for (int j=0; j < _row; j++) {
            T[i * _row + j] = _matrix[j * _col + i];
        }
    }
    // _row += _col;
    // _col = _row - _col;
    // _row -= _col;

    return T;
}

vector<float> matrix::dot(vector<float> mat, int r, int c) {
    if ( _col != r) { cout << "invalid dimensions"; _flag=1; vector<float> err; return err; }
    vector<float> _dot(_row * c);

    for (int x=0; x < _row; x++) { // row of mat_1
        for (int y=0; y < c; y++) { // col of mat_2
            for (int z=0; z < _col; z++) { // col of mat_1
                _dot[x * c + y] += _matrix[x * _col + z] * mat[z * c + y];
            }
        }
    }

    return _dot;
}