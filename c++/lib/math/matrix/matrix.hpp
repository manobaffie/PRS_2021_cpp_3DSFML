#ifndef matrix_HPP
#define matrix_HPP

#include <cmath>
#include <iostream>
#include <vector>

#define PI 3.14159265

struct matrix2D_s
{
    std::vector<std::vector<int>> matrix;

    static matrix2D_s Create(size_t const x, size_t const y)
    {
        matrix2D_s matrix;
        std::vector<std::vector<int>> matrix2D;
        for (size_t i = 0; i < y; i++) {
            std::vector<int> matrix1D;
            for (size_t j = 0; j < x; j++) {
                matrix1D.push_back(0);
            }
            matrix2D.push_back(matrix1D);
        }
        matrix.matrix = matrix2D;
        return (matrix);
    }

    static matrix2D_s Create(const std::vector<std::vector<int>> &matrix)
    {
        matrix2D_s matrix2D;

        matrix2D.matrix = matrix;

        return (matrix2D);
    }

    matrix2D_s operator+(const matrix2D_s &a)
    {
        if (this->matrix.size() != a.matrix.size() || 
        this->matrix[0].size() != a.matrix[0].size()) {
            std::cout << "[ERROR] -> Matrix A and B need to be the same in size." << std::endl;
            return (matrix2D_s::Create(0, 0));
        }

        matrix2D_s matrix;

        std::vector<std::vector<int>> matrix2D;
        for (size_t i = 0; i < a.matrix.size(); i++) {
            std::vector<int> matrix1D;
            for (size_t j = 0; j < a.matrix[0].size(); j++) {
                matrix1D.push_back(a.matrix[i][j] + this->matrix[i][j]);
            }
            matrix2D.push_back(matrix1D);
        }
        matrix.matrix = matrix2D;
        return (matrix);
    }

    matrix2D_s operator-(const matrix2D_s &a)
    {
        if (this->matrix.size() != a.matrix.size() || 
        this->matrix[0].size() != a.matrix[0].size()) {
            std::cout << "[ERROR] -> Matrix A and B need to be the same in size." << std::endl;
            return (matrix2D_s::Create(0, 0));
        }

        matrix2D_s matrix;

        std::vector<std::vector<int>> matrix2D;
        for (size_t i = 0; i < a.matrix.size(); i++) {
            std::vector<int> matrix1D;
            for (size_t j = 0; j < a.matrix[0].size(); j++) {
                matrix1D.push_back(a.matrix[i][j] - this->matrix[i][j]);
            }
            matrix2D.push_back(matrix1D);
        }
        matrix.matrix = matrix2D;
        return (matrix);
    }

    matrix2D_s operator*(const matrix2D_s &a)
    {
        if (this->matrix[0].size() != a.matrix.size()) {
            std::cout << "[ERROR] -> Matrix A column and B row amount need to be the same." << std::endl;
            return (matrix2D_s::Create(0, 0));
        }

        matrix2D_s matrix = matrix2D_s::Create(a.matrix[0].size(), this->matrix.size());

        std::vector<std::vector<int>> matrix2D;
        for (size_t i = 0; i < this->matrix.size(); i++) {
            std::vector<int> matrix1D;
            for (size_t j = 0; j < a.matrix[0].size(); j++) {
                int val = 0;
                for (size_t k = 0; k < this->matrix[0].size(); k++) {
                    val += (this->matrix[i][k] * a.matrix[k][j]);
                }
                matrix1D.push_back(val);
            }
            matrix2D.push_back(matrix1D);
        }
        matrix.matrix = matrix2D;
        return (matrix);
    }

    friend std::ostream& operator<<(std::ostream& os, const matrix2D_s &matrix)
    {
        for (size_t i = 0; i < matrix.matrix.size(); i++) {
            os << "[ ";
            for (size_t j = 0; j < matrix.matrix[0].size(); j++) {
                os << matrix.matrix[i][j] << " ";
            }
            os << "]" << std::endl;
        }
        return (os);
    }
};

#endif