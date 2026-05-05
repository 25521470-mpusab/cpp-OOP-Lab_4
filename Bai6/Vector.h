#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class Vector {
private:
    int soChieu;
    double* toaDo;

public:
    Vector();
    Vector(int n);
    Vector(const Vector& v); // copy constructor
    ~Vector();

    void set(int n);

    double tinhDoDai() const;

    Vector& operator=(const Vector& v); // tạo vùng nhớ 
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    double operator*(const Vector& v) const;
    bool operator==(const Vector& v) const; // so sánh 2 vector

    friend istream& operator>>(istream& in, Vector& v);
    friend ostream& operator<<(ostream& out, const Vector& v);
};

#endif