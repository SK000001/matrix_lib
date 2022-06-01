#ifndef matrix_hpp
#define matrix_hpp

#include <iostream>
#include <vector>
using namespace std;

class matrix {

    public:
        matrix();
        ~matrix();
        int size() {return _size; };
        int row() {return _row; };
        int col() {return _col; };
        vector<float> _matrix_() {return _matrix; }
        vector<float> createMatrix(int r, int c);
        vector<float> transpose();
        vector<float> dot(vector<float> mat, int r, int c);

    private:
        int _row;
        int _col;
        int _size;
        vector<float> _matrix;
};

#endif