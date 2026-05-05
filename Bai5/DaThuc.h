#ifndef DATHUC_H
#define DATHUC_H
#include <iostream>
using namespace std;

class DaThuc {
private:
    int bac;
    double* heSo;

public:
    DaThuc();
    DaThuc(int n);
    DaThuc(const DaThuc& dt); // copy constructor
    ~DaThuc();

    void set(int bac);
    double tinhGiaTri(double x) const;

    DaThuc operator+(const DaThuc& dt) const;
    DaThuc operator-(const DaThuc& dt) const;
    DaThuc operator*(const DaThuc& dt) const;

    DaThuc& operator=(const DaThuc& dt); // tạo vùng nhớ riêng cho b

    friend istream& operator>>(istream& in, DaThuc& dt);
    friend ostream& operator<<(ostream& out, const DaThuc& dt);
};

#endif