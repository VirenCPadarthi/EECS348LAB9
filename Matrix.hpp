#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <iomanip> // for formatting output

using namespace std;

template<typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int size;

public:
    // Constructor to initialize matrix with given size
    Matrix(int n) : size(n) {
        data.resize(n, vector<T>(n));
    }

    // Overload >> to read matrix data from file
    friend istream& operator>>(istream& is, Matrix<T>& mat) {
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j) {
                is >> mat.data[i][j];
            }
        }
        return is;
    }

    // Overload << to display matrix
    friend ostream& operator<<(ostream& os, const Matrix<T>& mat) {
        for (int i = 0; i < mat.size; ++i) {
            for (int j = 0; j < mat.size; ++j) {
                os << setw(4) << mat.data[i][j];
            }
            os << endl;
        }
        return os;
    }

    // Operator overloading for matrix addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Operator overloading for matrix multiplication
    Matrix<T> operator*(const Matrix<T>& other) const {
        Matrix<T> result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < size; ++k) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Function to calculate sum of main and secondary diagonal elements
    T sumDiagonals() const {
        T sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += data[i][i]; // main diagonal
            sum += data[i][size - 1 - i]; // secondary diagonal
        }
        return sum;
    }

    // Function to swap rows
    void swapRows(int row1, int row2) {
        if (row1 >= 0 && row1 < size && row2 >= 0 && row2 < size) {
            swap(data[row1], data[row2]);
        }
    }

    // Function to swap columns
    void swapColumns(int col1, int col2) {
        if (col1 >= 0 && col1 < size && col2 >= 0 && col2 < size) {
            for (int i = 0; i < size; ++i) {
                swap(data[i][col1], data[i][col2]);
            }
        }
    }

    // Function to update an element
    void updateElement(int row, int col, T value) {
        if (row >= 0 && row < size && col >= 0 && col < size) {
            data[row][col] = value;
        }
    }
};

#endif
