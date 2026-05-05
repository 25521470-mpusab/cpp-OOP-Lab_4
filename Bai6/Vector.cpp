#include "Vector.h"
#include <cmath>
#include <string>
using namespace std;

const double EPS = 1e-9;

/*
Đầu vào:
    chuỗi ký tự
Đầu ra:
    true nếu là số nguyên dương
    false nếu không hợp lệ
Hướng giải thuật:
    duyệt từng ký tự và kiểm tra có phải chữ số hay không
*/
bool laSoNguyenDuong(string s) {
    if (s.empty()) return false;

    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    return true;
}

/*
Constructor mặc định
Đầu vào:
    không có
Đầu ra:
    tạo vector mặc định 1 chiều = (0)
Hướng giải thuật:
    cấp phát mảng 1 phần tử và gán bằng 0
*/
Vector::Vector() {
    soChieu = 1;
    toaDo = new double[1];
    toaDo[0] = 0;
}

/*
Constructor có tham số
Đầu vào:
    số chiều n
Đầu ra:
    tạo vector n chiều
Điều kiện:
    n > 0
Hướng giải thuật:
    nếu n không hợp lệ thì gán mặc định = 1
    cấp phát mảng và khởi tạo các phần tử = 0
*/
Vector::Vector(int n) {
    if (n <= 0)
        n = 1;

    soChieu = n;
    toaDo = new double[soChieu];

    for (int i = 0; i < soChieu; i++) {
        toaDo[i] = 0;
    }
}

/*
Copy constructor
Đầu vào:
    1 vector khác
Đầu ra:
    tạo bản sao độc lập của vector đó
Hướng giải thuật:
    cấp phát vùng nhớ mới
    sao chép từng tọa độ
*/
Vector::Vector(const Vector& v) {
    soChieu = v.soChieu;
    toaDo = new double[soChieu];

    for (int i = 0; i < soChieu; i++) {
        toaDo[i] = v.toaDo[i];
    }
}

/*
Destructor
Đầu vào:
    không có
Đầu ra:
    giải phóng bộ nhớ động
Hướng giải thuật:
    dùng delete[] để tránh rò rỉ bộ nhớ
*/
Vector::~Vector() {
    delete[] toaDo;
}

/*
Đầu vào:
số chiều mới
Đầu ra:
    thiết lập lại vector
Điều kiện:
    n > 0
Hướng giải thuật:
    giải phóng vùng nhớ cũ
    cấp phát lại vùng nhớ mới
    gán toàn bộ bằng 0
*/
void Vector::set(int n) {
    if (n <= 0) {
        cout << "So chieu khong hop le!\n";
        return;
    }

    delete[] toaDo;

    soChieu = n;
    toaDo = new double[soChieu];

    for (int i = 0; i < soChieu; i++) {
        toaDo[i] = 0;
    }
}

/*
Đầu vào:
    vector hiện tại
Đầu ra:
    độ dài vector
Hướng giải thuật:
    áp dụng công thức:
    sqrt(x1^2 + x2^2 + ... + xn^2)
*/
double Vector::tinhDoDai() const {
    double tong = 0;

    for (int i = 0; i < soChieu; i++) {
        tong += toaDo[i] * toaDo[i];
    }

    return sqrt(tong);
}

/*
Đầu vào:
    vector khác
Đầu ra:
    gán dữ liệu của vector khác vào vector hiện tại
Hướng giải thuật:
    kiểm tra tự gán
    giải phóng vùng nhớ cũ
    cấp phát lại và sao chép dữ liệu
*/
Vector& Vector::operator=(const Vector& v) {
    if (this == &v)
        return *this;

    delete[] toaDo;

    soChieu = v.soChieu;
    toaDo = new double[soChieu];

    for (int i = 0; i < soChieu; i++) {
        toaDo[i] = v.toaDo[i];
    }

    return *this;
}

/*
Toán tử cộng
Đầu vào:
    2 vector
Đầu ra:
    vector tổng
Điều kiện:
    số chiều phải bằng nhau
Hướng giải thuật:
    cộng từng tọa độ tương ứng
*/
Vector Vector::operator+(const Vector& v) const {
    if (soChieu != v.soChieu) {
        cout << "Khong the cong hai vector khac so chieu!\n";
        return Vector();
    }

    Vector kq(soChieu);

    for (int i = 0; i < soChieu; i++) {
        kq.toaDo[i] = toaDo[i] + v.toaDo[i];
    }

    return kq;
}

/*
Toán tử trừ
Đầu vào:
    2 vector
Đầu ra:
    vector hiệu
Điều kiện:
    số chiều phải bằng nhau
Hướng giải thuật:
    trừ từng tọa độ tương ứng
*/
Vector Vector::operator-(const Vector& v) const {
    if (soChieu != v.soChieu) {
        cout << "Khong the tru hai vector khac so chieu!\n";
        return Vector();
    }

    Vector kq(soChieu);

    for (int i = 0; i < soChieu; i++) {
        kq.toaDo[i] = toaDo[i] - v.toaDo[i];
    }

    return kq;
}

/*
Toán tử tích vô hướng
Đầu vào:
    2 vector
Đầu ra:
    giá trị tích vô hướng
Điều kiện:
    số chiều phải bằng nhau
Hướng giải thuật:
    nhân từng tọa độ rồi cộng lại
*/
double Vector::operator*(const Vector& v) const {
    if (soChieu != v.soChieu) {
        cout << "Khong the tinh tich vo huong hai vector khac so chieu!\n";
        return 0;
    }

    double tong = 0;

    for (int i = 0; i < soChieu; i++) {
        tong += toaDo[i] * v.toaDo[i];
    }

    return tong;
}

/*
Toán tử so sánh bằng
Đầu vào:
    2 vector
Đầu ra:
    true nếu bằng nhau
    false nếu khác nhau
Hướng giải thuật:
    so sánh số chiều
    so sánh từng tọa độ với sai số EPS
*/
bool Vector::operator==(const Vector& v) const {
    if (soChieu != v.soChieu)
        return false;

    for (int i = 0; i < soChieu; i++) {
        if (fabs(toaDo[i] - v.toaDo[i]) > EPS)
            return false;
    }

    return true;
}

/*
Toán tử nhập
Đầu vào:
    số chiều và các tọa độ
Đầu ra:
    vector hợp lệ
Điều kiện:
    số chiều là số nguyên dương
    số chiều > 0
    tọa độ phải là số
Hướng giải thuật:
    nhập số chiều
    kiểm tra hợp lệ
    cấp phát mảng
    nhập từng tọa độ
*/
istream& operator>>(istream& in, Vector& v) {
    string input;

    while (true) {
        cout << "Nhap so chieu: ";
        in >> input;

        if (laSoNguyenDuong(input)) {
            try {
                v.soChieu = stoi(input);

                if (v.soChieu > 0 && v.soChieu <= 1000)
                    break;
            }
            catch (...) {
            }
        }

        cout << "So chieu khong hop le!\n";
    }

    delete[] v.toaDo;
    v.toaDo = new double[v.soChieu];

    for (int i = 0; i < v.soChieu; i++) {
        while (true) {
            cout << "Nhap toa do [" << i << "]: ";
            in >> v.toaDo[i];

            if (in.fail()) {
                cout << "Chi duoc nhap so!\n";
                in.clear();
                in.ignore(10000, '\n');
            }
            else {
                break;
            }
        }
    }

    return in;
}

/*
Toán tử xuất
Đầu vào:
    vector
Đầu ra:
    xuất vector dạng (a, b, c, ...)
Hướng giải thuật:
    duyệt lần lượt các tọa độ
    thêm dấu phẩy giữa các phần tử
*/
ostream& operator<<(ostream& out, const Vector& v) {
    out << "(";

    for (int i = 0; i < v.soChieu; i++) {
        out << v.toaDo[i];

        if (i != v.soChieu - 1)
            out << ", ";
    }

    out << ")";

    return out;
}