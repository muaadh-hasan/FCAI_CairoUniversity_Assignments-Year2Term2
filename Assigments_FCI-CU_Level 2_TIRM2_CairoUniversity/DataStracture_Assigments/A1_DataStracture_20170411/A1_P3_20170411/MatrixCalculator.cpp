// No error handling what so ever, make sure of your input...
// Only the mathematical constraints of matrix addition, subtraction and multiplication were added.

#include "MatrixCalculator.h"
#include <iostream>
#include "Matrix.h"

using std::cout;
using std::endl;
using std::flush;
using std::cin;

MatrixCalculator::MatrixCalculator() {
}

void MatrixCalculator::play() {
    cout << "Welcome to Matrix Calculator\n"
         << "___________________________________" << endl;

    while (1) {
        cout << "\n1- Perform Matrix Addition\n"
             << "2- Perform Matrix Subtraction\n"
             << "3- Perform Matrix Multiplication\n"
             << "4- Matrix Transpose\n"
             << "5- Quit\n"
             << "Please enter the # of the operation desired: " << flush ;

        char op;
        cin >> op;

        if (op > '0' && op < '4') {
            binary(op);
        }
        else if (op == '4') {
            unary(op);
        }
        else if (op == '5') {
            cout << "Quitting (Mourad) Matrix Calculator..." << endl;
            return;
        }
        else {
            cout << "Invalid operation # entered." << endl;
        }
    }
}

void MatrixCalculator::binary(char op) {
    unsigned int lhs_r, lhs_c, rhs_r, rhs_c;

    cout << "Please enter the row and column size of your lhs matrix separated by space: " << flush;
    cin >> lhs_r >> lhs_c;

    cout << "Please enter the row and column size of your rhs matrix separated by space: " << flush;
    cin >> rhs_r >> rhs_c;

    // Mathematical Constraints
    switch (op) {
    case '1':
    case '2':
        if (lhs_r != rhs_r || lhs_c != rhs_c) {
            cout << "The operation could not be performed, row and column sizes must be consistent between both matrices." << endl;
            return;
        }
        break;
    case '3':
        if (lhs_c != rhs_r) {
            cout << "The operation could not be performed, the lhs column size is not equal to the rhs row size." << endl;
            return;
        }
        break;
    }

    Matrix<double> lhs(lhs_r, lhs_c), rhs(rhs_r, rhs_c);

    cout << "Please enter your lhs matrix:" << endl;
    cin >> lhs;

    cout << "Please enter your rhs matrix: " << endl;
    cin >> rhs;

    // Execution

    cout << "The result is:\n";

    switch (op) {
    case '1':
        cout << (lhs + rhs) << endl;
        break;
    case '2':
        cout << (lhs - rhs) << endl;
        break;
    case '3':
        cout << (lhs * rhs) << endl;
        break;
    }
}

void MatrixCalculator::unary(char op) {
    unsigned int mat_r, mat_c;

    cout << "Please enter the row and column size of your matrix separated by space: ";
    cin >> mat_r >> mat_c;

    Matrix<double> mat(mat_r, mat_c);

    cout << "Please enter your matrix: " << endl;
    cin >> mat;

    cout << "The result is:\n";
    switch (op) {
    case '4':
        cout << mat.transpose() << endl;
        break;
    }
}

