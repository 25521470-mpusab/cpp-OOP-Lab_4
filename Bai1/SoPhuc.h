#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>
using namespace std;

class SoPhuc {
private:
    double thuc; // phần thực
    double ao;   // phần ảo

public:
    SoPhuc();
    SoPhuc(double, double = 0);  
    ~SoPhuc();

    void set(double, double = 0);

    SoPhuc operator + (const SoPhuc&);
    SoPhuc operator - (const SoPhuc&);
    SoPhuc operator * (const SoPhuc&);
    SoPhuc operator / (const SoPhuc&);

    bool operator == (const SoPhuc&);
    bool operator != (const SoPhuc&);

    // Nhập, xuất
    friend ostream& operator << (ostream&, const SoPhuc&);
    friend istream& operator >> (istream&, SoPhuc&);
};

#endif