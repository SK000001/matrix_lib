#ifndef matrix_hpp
#define matrix_hpp

#include <iostream>
#include <vector>

class matrix {

    public:
        // matrix() = default;
        // ~matrix();
        int size() {return _size; }
        int row() {return _row; };
        int col() {return _col; };
        int flag() {return _flag; }
        std::vector<float> _matrix_() {return _matrix; }
        std::vector<float> createMatrix(int r, int c);
        std::vector<float> transpose();
        std::vector<float> dot(matrix *mat);
        std::vector<float> sum(matrix *mat);

    private:
        int _row;
        int _col;
        int _size;
        std::vector<float> _matrix;
        int _flag;
};

#endif