#include "Date.h"
#include <string>
#include <iostream>
using namespace std;

/*
Đầu vào: chuỗi
Đầu ra:
    true nếu là số nguyên
    false nếu không phải số nguyên
*/
bool laSoNguyen(string s) {
    if (s.empty()) return false;

    int i = 0;
    if (s[0] == '-') {
        if (s.length() == 1) return false;
        i = 1;
    }

    for (; i < (int)s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    return true;
}

int main() {
    Date d1, d2;

    cout << "Nhap ngay thu nhat:\n";
    cin >> d1;

    cout << "Nhap ngay thu hai:\n";
    cin >> d2;

    cout << "Ngay thu nhat: " << d1 << endl;
    cout << "Ngay thu hai: " << d2 << endl;

    int soNgay;
    string input;

    // nhập số ngày cộng
    while (true) {
        cout << "Nhap so ngay muon cong: ";
        cin >> input;

        if (laSoNguyen(input)) {
            soNgay = stoi(input);
            break;
        } else {
            cout << "Loi! Phai nhap so nguyen.\n";
        }
    }

    cout << "Ket qua cong: " << d1 + soNgay << endl;

    // nhập số ngày trừ
    while (true) {
        cout << "Nhap so ngay muon tru: ";
        cin >> input;

        if (laSoNguyen(input)) {
            soNgay = stoi(input);
            break;
        } else {
            cout << "Loi! Phai nhap so nguyen.\n";
        }
    }

    cout << "Ket qua tru: " << d1 - soNgay << endl;

    // tăng 1 ngày
    ++d1;
    cout << "Sau khi cong 1 ngay: " << d1 << endl;

    // giảm 1 ngày
    --d1;
    cout << "Sau khi tru 1 ngay: " << d1 << endl;

    // khoảng cách giữa 2 ngày
    cout << "Khoang cach giua hai ngay: " << (d1 - d2) << " ngay\n";

    // bài toán lãi suất ngân hàng
    Date ngayGui, ngayRut;
    double tienGoc;
    double laiSuat;

    cout << "\nNhap ngay gui:\n";
    cin >> ngayGui;

    cout << "Nhap ngay rut:\n";
    cin >> ngayRut;

    cout << "Nhap so tien gui: ";
    cin >> tienGoc;

    cout << "Nhap lai suat (%/nam): ";
    cin >> laiSuat;

    int tongSoNgay = ngayRut - ngayGui;

    double tienLai = tienGoc * (laiSuat / 100) * tongSoNgay / 365;
    double tongTien = tienGoc + tienLai;

    cout << "\nNgay gui: " << ngayGui << endl;
    cout << "Ngay rut: " << ngayRut << endl;
    cout << "So ngay gui: " << tongSoNgay << endl;
    cout << "Tien lai: " << tienLai << endl;
    cout << "Tong nhan: " << tongTien << endl;

    return 0;
}