#include "DaThuc.h"

int main() {
    DaThuc a, b;

    cout << "Nhap da thuc thu nhat:\n";
    cin >> a;

    cout << "\nNhap da thuc thu hai:\n";
    cin >> b;

    cout << "\nDa thuc thu nhat: " << a << endl;
    cout << "Da thuc thu hai: " << b << endl;

    DaThuc tong = a + b;
    DaThuc hieu = a - b;
    DaThuc tich = a * b;

    cout << "\nTong hai da thuc: " << tong << endl;
    cout << "Hieu hai da thuc: " << hieu << endl;
    cout << "Tich hai da thuc: " << tich << endl;

    // nhập x để tính giá trị của cả 2 đa thức
    double x;
    cout << "\nNhap gia tri x: ";
    cin >> x;

    cout << "Gia tri da thuc thu nhat tai x = " 
         << x << " la: " 
         << a.tinhGiaTri(x) << endl;

    cout << "Gia tri da thuc thu hai tai x = " 
         << x << " la: " 
         << b.tinhGiaTri(x) << endl;

    return 0;
}