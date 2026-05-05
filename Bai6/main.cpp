#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
    Vector v1, v2;

    cout << "Nhap vector thu 1:\n";
    cin >> v1;

    cout << "\nNhap vector thu 2:\n";
    cin >> v2;

    cout << "\nVector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;

    cout << "\nTong 2 vector: " << v1 + v2 << endl;
    cout << "Hieu 2 vector: " << v1 - v2 << endl;
    cout << "Tich vo huong 2 vector: " << v1 * v2 << endl;

    cout << "\nDo dai vector 1: " << v1.tinhDoDai() << endl;
    cout << "Do dai vector 2: " << v2.tinhDoDai() << endl;

    if (v1 == v2)
        cout << "\nHai vector bang nhau\n";
    else
        cout << "\nHai vector khac nhau\n";

    return 0;
}