#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
private:
    int ngay;
    int thang;
    int nam;

public:
    Date();
    Date(int n, int t, int y);
    ~Date();

    void set(int n, int t, int y);
    
    bool kiemTraNgayHopLe();

    Date operator+(int soNgay);
    Date operator-(int soNgay);

    int operator-(const Date& other);

    Date& operator++();
    Date& operator--();

    friend istream& operator>>(istream& in, Date& d);
    friend ostream& operator<<(ostream& out, const Date& d);
};

#endif