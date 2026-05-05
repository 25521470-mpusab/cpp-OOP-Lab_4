#include "PhanSo.h"
#include <iostream>
#include <string>

using namespace std;

/*
Hàm kiểm tra chuỗi có phải số nguyên hợp lệ không
Input: chuỗi s
Output:
- true: nếu s là số nguyên hợp lệ
- false: nếu không hợp lệ
Giải thuật:
- Cho phép dấu '-' ở đầu
- Các ký tự còn lại phải là chữ số
*/
bool laSoNguyen(string s) {
    if (s.empty()) return false;

    int i = 0;

    if (s[0] == '-') {
        if (s.size() == 1) return false;
        i = 1;
    }

    for (; i < (int)s.size(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    return true;
}

/*
Hàm tìm UCLN của 2 số nguyên
Input: 2 số nguyên a, b
Output: UCLN của a và b
Giải thuật:
- Đưa về số dương
- Dùng thuật toán Euclid
*/
int UCLN(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

/*
Constructor mặc định
Input: không có
Output: tạo phân số 0/1
Giải thuật:
- Khởi tạo tử = 0
- Khởi tạo mẫu = 1
*/
PhanSo::PhanSo() {
    tu = 0;
    mau = 1;
}

/*
Constructor có tham số
Input:
- tử số
- mẫu số
Output: tạo phân số tương ứng
Giải thuật:
- Gọi set để kiểm tra và rút gọn
*/
PhanSo::PhanSo(int tu, int mau) {
    set(tu, mau);
}

/*
Destructor
Input: không có
Output: hủy đối tượng
Giải thuật:
- Không cần xử lý gì thêm
*/
PhanSo::~PhanSo() {
}

/*
Thiết lập giá trị phân số
Input:
- tử số
- mẫu số
Output: cập nhật phân số
Giải thuật:
- Nếu mẫu bằng 0 thì gán mẫu = 1
- Rút gọn phân số
*/
void PhanSo::set(int tu, int mau) {
    this->tu = tu;

    if (mau == 0)
        this->mau = 1;
    else
        this->mau = mau;

    rutGon();
}

/*
Rút gọn phân số
Input: phân số hiện tại
Output: phân số tối giản
Giải thuật:
- Tìm UCLN
- Chia tử và mẫu cho UCLN
- Đưa dấu âm lên tử
*/
void PhanSo::rutGon() {
    int ucln = UCLN(tu, mau);

    tu /= ucln;
    mau /= ucln;

    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

/*
Phép cộng phân số
Input: 2 phân số
Output: tổng 2 phân số
Giải thuật:
- Quy đồng mẫu
- Cộng tử
- Rút gọn
*/
PhanSo PhanSo::operator+(const PhanSo &ps) {
    PhanSo kq;

    kq.tu = tu * ps.mau + ps.tu * mau;
    kq.mau = mau * ps.mau;

    kq.rutGon();

    return kq;
}

/*
Phép trừ phân số
Input: 2 phân số
Output: hiệu 2 phân số
Giải thuật:
- Quy đồng mẫu
- Trừ tử
- Rút gọn
*/
PhanSo PhanSo::operator-(const PhanSo &ps) {
    PhanSo kq;

    kq.tu = tu * ps.mau - ps.tu * mau;
    kq.mau = mau * ps.mau;

    kq.rutGon();

    return kq;
}

/*
Phép nhân phân số
Input: 2 phân số
Output: tích 2 phân số
Giải thuật:
- Nhân tử với tử
- Nhân mẫu với mẫu
- Rút gọn
*/
PhanSo PhanSo::operator*(const PhanSo &ps) {
    PhanSo kq;

    kq.tu = tu * ps.tu;
    kq.mau = mau * ps.mau;

    kq.rutGon();

    return kq;
}

/*
Phép chia phân số
Input: 2 phân số
Output: thương 2 phân số
Giải thuật:
- Kiểm tra phân số chia khác 0
- Nhân với nghịch đảo
- Rút gọn
*/
PhanSo PhanSo::operator/(const PhanSo &ps) {
    PhanSo kq;

    if (ps.tu == 0) {
        cout << "Loi! Khong the chia cho phan so 0.\n";
        return kq;
    }

    kq.tu = tu * ps.mau;
    kq.mau = mau * ps.tu;

    kq.rutGon();

    return kq;
}

/*
So sánh bằng
Input: 2 phân số
Output:
- true nếu bằng nhau
- false nếu khác nhau
Giải thuật:
- So sánh nhân chéo
*/
bool PhanSo::operator==(const PhanSo &ps) {
    return tu * ps.mau == ps.tu * mau;
}

/*
So sánh lớn hơn
Input: 2 phân số
Output:
- true nếu lớn hơn
- false nếu không
Giải thuật:
- So sánh nhân chéo
*/
bool PhanSo::operator>(const PhanSo &ps) {
    return tu * ps.mau > ps.tu * mau;
}

/*
So sánh nhỏ hơn
Input: 2 phân số
Output:
- true nếu nhỏ hơn
- false nếu không
Giải thuật:
- So sánh nhân chéo
*/
bool PhanSo::operator<(const PhanSo &ps) {
    return tu * ps.mau < ps.tu * mau;
}

/*
Toán tử nhập >>
Input:
- luồng nhập
- phân số cần nhập
Output: phân số hợp lệ
Giải thuật:
- Nhập tử dưới dạng chuỗi
- Kiểm tra số nguyên
- Nhập mẫu dưới dạng chuỗi
- Kiểm tra số nguyên và mẫu khác 0
- Rút gọn phân số
*/
istream& operator>>(istream &in, PhanSo &ps) {
    string s;

    // nhập tử số
    while (true) {
        cout << "Nhap tu so: ";
        in >> s;

        if (laSoNguyen(s)) {
            ps.tu = stoi(s);
            break;
        }
        else {
            cout << "Loi! Tu so phai la so nguyen.\n";
        }
    }

    // nhập mẫu số
    while (true) {
        cout << "Nhap mau so (khac 0): ";
        in >> s;

        if (!laSoNguyen(s)) {
            cout << "Loi! Mau so phai la so nguyen.\n";
        }
        else {
            ps.mau = stoi(s);

            if (ps.mau == 0) {
                cout << "Loi! Mau so phai khac 0.\n";
            }
            else {
                break;
            }
        }
    }

    ps.rutGon();

    return in;
}

/*
Toán tử xuất <<
Input: phân số
Output: phân số dạng a/b
Giải thuật:
- Nếu tử = 0 in 0
- Nếu mẫu = 1 in tử
- Ngược lại in dạng a/b
*/
ostream& operator<<(ostream &out, const PhanSo &ps) {
    if (ps.tu == 0)
        out << 0;
    else if (ps.mau == 1)
        out << ps.tu;
    else
        out << ps.tu << "/" << ps.mau;

    return out;
}