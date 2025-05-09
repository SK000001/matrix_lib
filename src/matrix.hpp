#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

class Matrix {

    public:
        Matrix();
        Matrix(int rows, int cols);

        int size() const {return _size; }
        int row() const {return _row; };
        int col() const {return _col; };
        std::vector<float> get_matrix() const { return _matrix; }

        void createMatrix();
 
        std::vector<float> transpose() const;
        std::vector<float> dotProd(const Matrix& other) const;
        std::vector<float> dotDiv(const Matrix& other) const;   // dot division
        std::vector<float> sum(const Matrix& other) const;
        std::vector<float> diff(const Matrix& other) const;

        void display() const;

    private:
        int _row;
        int _col;
        int _size;
        std::vector<float> _matrix;
};

#endif