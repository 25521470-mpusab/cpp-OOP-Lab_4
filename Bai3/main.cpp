#include "Time.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
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
    Time t;
    cin >> t;

    cout << "Thoi diem vua nhap: " << t << endl;

    string input;
    int soGiay;

    // nhập số giây cộng
    while (true) {
        cout << "Nhap so giay muon cong: ";
        cin >> input;

        if (laSoNguyen(input)) {
            soGiay = stoi(input);
            break;
        } else {
            cout << "Loi! Phai nhap so nguyen.\n";
        }
    }

    Time tCong = t + soGiay;
    cout << "Sau khi cong: " << tCong << endl;

    // nhập số giây trừ
    while (true) {
        cout << "Nhap so giay muon tru: ";
        cin >> input;

        if (laSoNguyen(input)) {
            soGiay = stoi(input);
            break;
        } else {
            cout << "Loi! Phai nhap so nguyen.\n";
        }
    }

    Time tTru = t - soGiay;
    cout << "Sau khi tru: " << tTru << endl;

    ++t;
    cout << "Sau ++: " << t << endl;

    --t;
    cout << "Sau --: " << t << endl;
    
    
    // Tạo đồng hồ in ở góc trên bên phải màn hình.
    Time dongHo;

    cin >> dongHo;

    while (true) {
        // đẩy sang phải (giả lập góc phải)
        cout << "\r\t\t\t\t\t" << dongHo << flush;

        this_thread::sleep_for(chrono::seconds(1));

        ++dongHo;
        return 0;
    }

    return 0;
}