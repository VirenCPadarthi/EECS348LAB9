#include <iostream>
#include <fstream>
#include "Matrix.hpp"

using namespace std;

int main() {
    string filename;
    cout << "Enter input file name: ";
    cin >> filename;

    int size, type;
    cout << "Enter matrix size: ";
    cin >> size;
    cout << "Enter type (0 = int, 1 = double): ";
    cin >> type;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    if (type == 0) {
        Matrix<int> mat1(size), mat2(size);
        file >> mat1 >> mat2;

        cout << "\nMatrix 1:\n" << mat1;
        cout << "\nMatrix 2:\n" << mat2;

        cout << "\nMatrix Addition:\n" << (mat1 + mat2);
        cout << "\nMatrix Multiplication:\n" << (mat1 * mat2);

        cout << "\nSum of Diagonals (Matrix 1): " << mat1.sumDiagonals() << endl;

        mat1.swapRows(0, 3);
        cout << "\nAfter Swapping Rows 0 and 3 (Matrix 1):\n" << mat1;

        mat1.swapColumns(0, 3);
        cout << "\nAfter Swapping Columns 0 and 3 (Matrix 1):\n" << mat1;

        mat1.updateElement(1, 1, 99);
        cout << "\nAfter Updating Element (1,1) to 99 (Matrix 1):\n" << mat1;
    }
    else if (type == 1) {
        Matrix<double> mat1(size), mat2(size);
        file >> mat1 >> mat2;

        cout << "\nMatrix 1:\n" << mat1;
        cout << "\nMatrix 2:\n" << mat2;

        cout << "\nMatrix Addition:\n" << (mat1 + mat2);
        cout << "\nMatrix Multiplication:\n" << (mat1 * mat2);

        cout << "\nSum of Diagonals (Matrix 1): " << mat1.sumDiagonals() << endl;

        mat1.swapRows(0, 3);
        cout << "\nAfter Swapping Rows 0 and 3 (Matrix 1):\n" << mat1;

        mat1.swapColumns(0, 3);
        cout << "\nAfter Swapping Columns 0 and 3 (Matrix 1):\n" << mat1;

        mat1.updateElement(1, 1, 99.99);
        cout << "\nAfter Updating Element (1,1) to 99.99 (Matrix 1):\n" << mat1;
    }
    else {
        cout << "Unsupported type." << endl;
        return 1;
    }

    file.close();
    return 0;
}
