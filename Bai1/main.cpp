#include "SoPhuc.h"

int main() {
    SoPhuc a, b;

    cout << "Nhap so phuc a (phan thuc phan ao): ";
    cin >> a;

    cout << "Nhap so phuc b (phan thuc phan ao): ";
    cin >> b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;

    if (a == b)
        cout << "a == b" << endl;
    else
        cout << "a != b" << endl;

    return 0;
}