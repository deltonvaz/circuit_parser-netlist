#ifndef TOPICOSI_MATRIX_H
#define TOPICOSI_MATRIX_H

#include <iostream>

class Matrix {
public:
    Matrix(int, int);
    Matrix();
    ~Matrix();
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);

    inline double& operator()(int x, int y) { return p[x][y]; }

    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix& operator*=(double);
    Matrix& operator/=(double);
    Matrix  operator^(int);

    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    friend std::istream& operator>>(std::istream&, Matrix&);

    void swapRows(int, int);

    Matrix eliminateFirstLineAndColumn();
    Matrix eliminateFirstLine();
    static Matrix createIdentity(int);

    // functions on matrices
    static Matrix augment(Matrix, Matrix);
    Matrix gaussianEliminate();
    Matrix rowReduceFromGaussian();
    /*
     * Matrix inverse uses augmented, gaussianEliminate and rowReduceFromGaussian
     * */
    Matrix inverse();

private:
    int rows_, cols_;
    double **p;

    void allocSpace();
    Matrix expHelper(const Matrix&, int);
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);
Matrix operator/(const Matrix&, double);


#endif //TOPICOSI_MATRIX_H
