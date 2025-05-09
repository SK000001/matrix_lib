#include "matrix.hpp"
#include <stdexcept>
#include <limits>

Matrix::Matrix() : _row(0), _col(0), _size(0) {}

Matrix::Matrix(int rows, int cols) : _row(rows), _col(cols), _size(rows * cols) {
    _matrix.resize(_size);
}

void Matrix::createMatrix() {
    std::cout << "Enter " << _row * _col << " elements:" << std::endl;
    _matrix.resize(_row * _col);
    
    for (int i = 0; i < _size; ++i) {
        std::cout << "Element [" << i << "]: ";
        while (!(std::cin >> _matrix[i])) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again: ";
        }
    }
}

std::vector<float> Matrix::transpose() const {
    std::vector<float> T(_size);
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _col; ++j) {
            T[j * _row + i] = _matrix[i * _col + j];
        }
    }
    return T;
}

std::vector<float> Matrix::dotProd(const Matrix& other) const {
    if (_col != other.row()) {
        throw std::invalid_argument("Matrix dimensions mismatch for dot product");
    }
    std::vector<float> result(_row * other.col(), 0);
    const std::vector<float>& mat = other.get_matrix();
    for (int x = 0; x < _row; ++x) {
        for (int y = 0; y < other.col(); ++y) {
            for (int z = 0; z < _col; ++z) {
                result[x * other.col() + y] += _matrix[x * _col + z] * mat[z * other.col() + y];
            }
        }
    }
    return result;
}

std::vector<float> Matrix::dotDiv(const Matrix& other) const {
    if (_col != other.row()) {
        throw std::invalid_argument("Matrix dimensions mismatch for multiplication");
    }

    std::vector<float> result(_row * other.col(), 0.0f);
    const std::vector<float>& matB = other.get_matrix();

    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < other.col(); ++j) {
            float sum = 0.0f;
            for (int k = 0; k < _col; ++k) {
                sum += _matrix[i * _col + k] / matB[k * other.col() + j];
            }
            result[i * other.col() + j] = sum;
        }
    }

    return result;
}


std::vector<float> Matrix::sum(const Matrix& other) const {
    if (_row != other.row() || _col != other.col()) {
        throw std::invalid_argument("Matrix dimensions mismatch for addition");
    }
    std::vector<float> result(_size);
    const std::vector<float>& mat = other.get_matrix();
    for (int i = 0; i < _size; ++i) {
        result[i] = _matrix[i] + mat[i];
    }
    return result;
}

std::vector<float> Matrix::diff(const Matrix& other) const {
    if (_row != other.row() || _col != other.col()) {
        throw std::invalid_argument("Matrix dimensions mismatch for subtraction");
    }
    std::vector<float> result(_size);
    const std::vector<float>& mat = other.get_matrix();
    for (int i = 0; i < _size; ++i) {
        result[i] = _matrix[i] - mat[i];
    }
    return result;
}

void Matrix::display() const {
    for (int i = 0; i < _row; ++i) {
        for (int j = 0; j < _col; ++j) {
            std::cout << _matrix[i * _col + j] << " ";
        }
        std::cout << std::endl;
    }
}