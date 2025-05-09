#include "matrix.hpp"
#include <iostream>

int main() {
    int r1, c1, r2, c2;

    // MATRIX 1 CREATION
    std::cout << "Enter rows and columns for Matrix 1:\n";
    std::cin >> r1 >> c1;
    Matrix mat1(r1, c1);
    mat1.createMatrix();

    // MATRIX 2 CREATION
    std::cout << "\nEnter rows and columns for Matrix 2:\n";
    std::cin >> r2 >> c2;
    Matrix mat2(r2, c2);
    mat2.createMatrix();

    // PRINTING MATRIX 1
    std::cout << "\nMatrix 1:\n";
    mat1.display();

    // PRINTING MATRIX 2
    std::cout << "\nMatrix 2:\n";
    mat2.display();

    // MATRIX 1 TRANSPOSE
    std::cout << "\nMatrix 1 Transpose:\n";
    std::vector<float> t1 = mat1.transpose();
    for (int i = 0; i < c1; ++i) {
        for (int j = 0; j < r1; ++j) {
            std::cout << t1[i * r1 + j] << " ";
        }
        std::cout << "\n";
    }

    // MATRIX 2 TRANSPOSE
    std::cout << "\nMatrix 2 Transpose:\n";
    std::vector<float> t2 = mat2.transpose();
    for (int i = 0; i < c2; ++i) {
        for (int j = 0; j < r2; ++j) {
            std::cout << t2[i * r2 + j] << " ";
        }
        std::cout << "\n";
    }

    // DOT PRODUCT
    try {
        std::cout << "\nMatrix 1 <dotProd> Matrix 2:\n";
        std::vector<float> dot = mat1.dotProd(mat2);
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                std::cout << dot[i * c2 + j] << " ";
            }
            std::cout << "\n";
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Dot product error: " << e.what() << "\n";
    }

    // DOT DIVISION
    try {
        std::cout << "\nMatrix 1 <dotDiv> Matrix 2:\n";
        std::vector<float> mult = mat1.dotDiv(mat2);
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                std::cout << mult[i * c2 + j] << " ";
            }
            std::cout << "\n";
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "dot division error: " << e.what() << "\n";
    }

    // SUM
    try {
        std::cout << "\nMatrix 1 + Matrix 2:\n";
        std::vector<float> sum = mat1.sum(mat2);
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c1; ++j) {
                std::cout << sum[i * c1 + j] << " ";
            }
            std::cout << "\n";
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Addition error: " << e.what() << "\n";
    }

    // DIFFERENCE (mat1 - mat2)
    try {
        std::cout << "\nMatrix 1 - Matrix 2:\n";
        std::vector<float> diff = mat1.diff(mat2);
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c1; ++j) {
                std::cout << diff[i * c1 + j] << " ";
            }
            std::cout << "\n";
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Subtraction error: " << e.what() << "\n";
    }

    // DIFFERENCE (mat2 - mat1)
    try {
        std::cout << "\nMatrix 2 - Matrix 1:\n";
        std::vector<float> diff = mat2.diff(mat1);
        for (int i = 0; i < r2; ++i) {
            for (int j = 0; j < c2; ++j) {
                std::cout << diff[i * c2 + j] << " ";
            }
            std::cout << "\n";
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Subtraction error: " << e.what() << "\n";
    }

    return 0;
}
