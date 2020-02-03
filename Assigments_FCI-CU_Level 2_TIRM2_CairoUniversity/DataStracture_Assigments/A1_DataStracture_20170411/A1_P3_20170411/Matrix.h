#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <istream>

using std::ostream;
using std::istream;

template<class T1>
class Matrix {
private:
    unsigned int r, c;
    T1** mat;

public:
    explicit Matrix(unsigned int iR, unsigned int iC);

    ~Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    Matrix transpose() const;

    Matrix operator+(const Matrix& rhs) const;
    Matrix operator-(const Matrix& rhs) const;
    Matrix operator*(const Matrix& rhs) const;

    template<class T2>
    friend ostream& operator<<(ostream& os, const Matrix<T2>& rhs);

    template<class T2>
    friend istream& operator>>(istream& is, Matrix<T2>& rhs);
};

template<class T1>
Matrix<T1>::Matrix(unsigned int iR, unsigned int iC) : r(iR), c(iC) {
    mat = new T1*[r];
    for (unsigned int i = 0; i < r; i++) {
        mat[i] = new T1[c];
        for (unsigned int j = 0; j < c; j++) {
            mat[i][j] = 0;
        }
    }
}

template<class T1>
Matrix<T1>::~Matrix() {
    for (unsigned int i = 0; i < r; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

template<class T1>
Matrix<T1>::Matrix(const Matrix& rhs) {
    (r = rhs.r, c = rhs.c);

    mat = new T1*[r];
    for (unsigned int i = 0; i < r; i++) {
        mat[i] = new T1[c];
        for (unsigned int j = 0; j < c; j++) {
            mat[i][j] = rhs.mat[i][j];
        }
    }
}

template<class T1>
Matrix<T1>& Matrix<T1>::operator=(const Matrix& rhs) {
    for (unsigned int i = 0; i < r; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    (r = rhs.r, c = rhs.c);

    mat = new T1*[r];
    for (unsigned int i = 0; i < r; i++) {
        mat[i] = new T1[c];
        for (unsigned int j = 0; j < c; j++) {
            mat[i][j] = rhs.mat[i][j];
        }
    }
}

template<class T1>
Matrix<T1> Matrix<T1>::transpose() const {
    Matrix ret(c, r);
    for (unsigned int i = 0; i < c; i++) {
        for (unsigned int j = 0; j < r; j++) {
            ret.mat[i][j] = mat[j][i];
        }
    }
    return ret;
}

template<class T1>
Matrix<T1> Matrix<T1>::operator+(const Matrix& rhs) const {
    Matrix ret(r, c);
    for (unsigned int i = 0; i < r; i++) {
        for (unsigned int j = 0; j < c; j++) {
            ret.mat[i][j] = mat[i][j] + rhs.mat[i][j];

        }
    }
    return ret;
}

template<class T1>
Matrix<T1> Matrix<T1>::operator-(const Matrix& rhs) const {
    Matrix ret(r, c);
    for (unsigned int i = 0; i < r; i++) {
        for (unsigned int j = 0; j < c; j++) {
            ret.mat[i][j] = mat[i][j] - rhs.mat[i][j];

        }
    }
    return ret;
}

template<class T1>
Matrix<T1> Matrix<T1>::operator*(const Matrix& rhs) const {
    Matrix ret(r, rhs.c);
    for (unsigned int i = 0; i < r; i++) {
        for (unsigned int j = 0; j < rhs.c; j++) {
            for (unsigned int k = 0; k < c; k++) {
                ret.mat[i][j] += mat[i][k] * rhs.mat[k][j];
            }
        }
    }
    return ret;
}

template<class T2>
ostream& operator<<(ostream& os, const Matrix<T2>& rhs) {
    for (unsigned int i = 0; i < rhs.r; i++) {
        for (unsigned int j = 0; j < rhs.c; j++) {
            os << rhs.mat[i][j];
            os << '\t';
        }

        if (i != rhs.r - 1) {
            os << '\n';
        }
    }
    return os;
}

template<class T2>
istream& operator>>(istream& is, Matrix<T2>& rhs) {
    for (unsigned int i = 0; i < rhs.r; i++) {
        for (unsigned int j = 0; j < rhs.c; j++) {
            is >> rhs.mat[i][j];
        }
    }
    return is;
}

#endif // MATRIX_H
