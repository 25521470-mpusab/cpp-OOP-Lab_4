#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time {
private:
    int gio;
    int phut;
    int giay;

public:
    Time();
    Time(int g, int p, int s);
    ~Time();

    void set(int g, int p, int s);

    // Toán tử cộng / trừ số giây
    Time operator+(int soGiay);
    Time operator-(int soGiay);

    // Prefix ++ --
    Time& operator++();
    Time& operator--();

    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, const Time& t);
};

#endif