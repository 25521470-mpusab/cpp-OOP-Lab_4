#include "PhanSo.h"

int main() {
    PhanSo a, b;

    cin >> a >> b;

    cout << "Tong: " << a + b << endl;
    cout << "Hieu: " << a - b << endl;
    cout << "Tich: " << a * b << endl;
    cout << "Thuong: " << a / b << endl;

    cout << "Bang nhau: " << (a == b) << endl;
    cout << "Lon hon: " << (a > b) << endl;
    cout << "Nho hon: " << (a < b) << endl;

    return 0;
}