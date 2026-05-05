#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

class Matrix {
private:
    int soDong;
    int soCot;
    double** giaTri; // mảng động 2 chiều

public:
    Matrix();
    Matrix(int dong, int cot);
    Matrix(const Matrix& m); // copy constructor
    ~Matrix();

    void set(int dong, int cot);
    int getSoDong() const;
    int getSoCot() const;

    bool laMaTranVuong() const;
    double tinhDinhThuc() const;

    Matrix& operator=(const Matrix& m); // tạo vùng nhớ mới
    Matrix operator+(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix operator*(const Matrix& m) const; // tích 2 ma trận 

    double* nhanVector(const double* v, int n) const; // hàm tính tích của 1 ma trận và 1 vector

    friend istream& operator>>(istream& in, Matrix& m);
    friend ostream& operator<<(ostream& out, const Matrix& m);
};

#endif