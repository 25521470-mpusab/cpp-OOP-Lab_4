#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;

public:
    PhanSo();
    PhanSo(int, int = 1);
    ~PhanSo();

    void set(int, int = 1);
    void rutGon();

    PhanSo operator + (const PhanSo&);
    PhanSo operator - (const PhanSo&);
    PhanSo operator * (const PhanSo&);
    PhanSo operator / (const PhanSo&);

    bool operator == (const PhanSo&);
    bool operator > (const PhanSo&); // true nếu lớn hơn
    bool operator < (const PhanSo&); // true nếu nhỏ hơn

    friend ostream& operator << (ostream&, const PhanSo&);
    friend istream& operator >> (istream&, PhanSo&);
};

#endif