#include "DaThuc.h"
#include <cmath>
#include <string>
using namespace std;

/*
Đầu vào:
    chuỗi ký tự
Đầu ra:
    true: nếu chuỗi là số nguyên dương
    false: nếu chuỗi không hợp lệ
Hướng giải thuật:
    - kiểm tra chuỗi rỗng
    - duyệt từng ký tự
    - nếu có ký tự không phải số thì trả về false
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
    tạo đa thức mặc định P(x)=0
Hướng giải thuật:
    - đặt bậc = 0
    - cấp phát 1 phần tử
    - gán hệ số = 0
*/
DaThuc::DaThuc() {
    bac = 0;
    heSo = new double[1];
    heSo[0] = 0;
}

/*
Constructor có tham số
Đầu vào:
    bậc đa thức
Đầu ra:
    tạo đa thức bậc n với hệ số = 0
Hướng giải thuật:
    - gán bậc
    - cấp phát mảng hệ số
    - khởi tạo các hệ số bằng 0
*/
DaThuc::DaThuc(int n) {
    bac = n;
    heSo = new double[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heSo[i] = 0;
    }
}

/*
Copy constructor
Đầu vào:
    1 đa thức khác
Đầu ra:
    tạo bản sao độc lập
Hướng giải thuật:
    - copy bậc
    - cấp phát vùng nhớ mới
    - sao chép từng hệ số
*/
DaThuc::DaThuc(const DaThuc& dt) {
    bac = dt.bac;
    heSo = new double[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heSo[i] = dt.heSo[i];
    }
}

/*
Destructor
Đầu vào:
    không có
Đầu ra:
    giải phóng vùng nhớ động đã cấp phát
Hướng giải thuật:
    - delete mảng hệ số
*/
DaThuc::~DaThuc() {
    delete[] heSo;
}

/*
Đầu vào:
    bậc mới
Đầu ra:
    tạo lại đa thức mới
Hướng giải thuật:
    - xóa mảng cũ
    - cấp phát lại mảng mới
    - gán tất cả hệ số = 0
*/
void DaThuc::set(int bac) {
    delete[] heSo;

    this->bac = bac;
    heSo = new double[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heSo[i] = 0;
    }
}

/*
Đầu vào:
    x
Đầu ra:
    P(x)
Hướng giải thuật:
    dùng phương pháp Horner để giảm phép tính
*/
double DaThuc::tinhGiaTri(double x) const {
    double kq = 0;

    for (int i = bac; i >= 0; i--) {
        kq = kq * x + heSo[i];
    }

    return kq;
}

/*
Cộng hai đa thức
Đầu vào:
    đa thức dt
Đầu ra:
    đa thức tổng
Hướng giải thuật:
    - lấy bậc lớn nhất
    - cộng từng hệ số tương ứng
    - chuẩn hóa lại bậc
*/
DaThuc DaThuc::operator+(const DaThuc& dt) const {
    int maxBac = (bac > dt.bac) ? bac : dt.bac;
    DaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double a = (i <= bac) ? heSo[i] : 0;
        double b = (i <= dt.bac) ? dt.heSo[i] : 0;

        kq.heSo[i] = a + b;
    }

    while (kq.bac > 0 && kq.heSo[kq.bac] == 0) {
        kq.bac--;
    }

    return kq;
}

/*
Trừ hai đa thức
Đầu vào:
    đa thức dt
Đầu ra:
    đa thức hiệu
Hướng giải thuật:
    - lấy bậc lớn nhất
    - trừ từng hệ số tương ứng
    - chuẩn hóa lại bậc
*/
DaThuc DaThuc::operator-(const DaThuc& dt) const {
    int maxBac = (bac > dt.bac) ? bac : dt.bac;
    DaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double a = (i <= bac) ? heSo[i] : 0;
        double b = (i <= dt.bac) ? dt.heSo[i] : 0;

        kq.heSo[i] = a - b;
    }

    while (kq.bac > 0 && kq.heSo[kq.bac] == 0) {
        kq.bac--;
    }

    return kq;
}

/*
Nhân hai đa thức
Đầu vào:
    đa thức dt
Đầu ra:
    đa thức tích
Hướng giải thuật:
    - nhân từng cặp hệ số
    - cộng dồn vào vị trí tương ứng
    - chuẩn hóa lại bậc
*/
DaThuc DaThuc::operator*(const DaThuc& dt) const {
    DaThuc kq(bac + dt.bac);

    for (int i = 0; i <= bac; i++) {
        for (int j = 0; j <= dt.bac; j++) {
            kq.heSo[i + j] += heSo[i] * dt.heSo[j];
        }
    }

    while (kq.bac > 0 && kq.heSo[kq.bac] == 0) {
        kq.bac--;
    }

    return kq;
}

/*
Toán tử gán
Đầu vào:
    đa thức dt
Đầu ra:
    gán dữ liệu từ dt vào đối tượng hiện tại
Hướng giải thuật:
    - kiểm tra tự gán
    - giải phóng vùng nhớ cũ
    - cấp phát lại
    - copy dữ liệu
*/
DaThuc& DaThuc::operator=(const DaThuc& dt) {
    if (this == &dt)
        return *this;

    delete[] heSo;

    bac = dt.bac;
    heSo = new double[bac + 1];

    for (int i = 0; i <= bac; i++) {
        heSo[i] = dt.heSo[i];
    }

    return *this;
}

/*
Nhập đa thức
Đầu vào:
    bậc và các hệ số
Đầu ra:
    đối tượng đa thức hợp lệ
Điều kiện:
    - bậc phải >= 0
    - hệ số phải là số
Hướng giải thuật:
    - nhập bậc hợp lệ
    - cấp phát lại mảng
    - nhập từng hệ số
    - chuẩn hóa lại bậc
*/
istream& operator>>(istream& in, DaThuc& dt) {
    string input;
 // Nhập bậc
    while (true) {
        cout << "Nhap bac da thuc (>=0): ";
        in >> input;

        if (laSoNguyenDuong(input)) {
            dt.bac = stoi(input);
            break;
        }

        cout << "Bac khong hop le!\n";
    }

    // cấp phát lại mảng
    delete[] dt.heSo;
    dt.heSo = new double[dt.bac + 1];

    // Nhập hệ số
    for (int i = 0; i <= dt.bac; i++) {
        while (true) {
            cout << "Nhap he so a[" << i << "]: ";
            in >> dt.heSo[i];

            if (in.fail()) {
                cout << "He so khong hop le!\n";
                in.clear();
                in.ignore(10000, '\n');
            }
            else {
                break;
            }
        }
    }

    while (dt.bac > 0 && dt.heSo[dt.bac] == 0) {
        dt.bac--;
    }

    return in;
}

/*
Xuất đa thức
Đầu vào:
    đối tượng đa thức
Đầu ra:
    đa thức dạng toán học
Hướng giải thuật:
    - duyệt từ bậc cao xuống thấp
    - bỏ hệ số = 0
    - xử lý dấu + -
    - xử lý hệ số 1 và -1
*/
ostream& operator<<(ostream& out, const DaThuc& dt) {
    bool coIn = false; // kiểm tra đã in gì chưa

    for (int i = dt.bac; i >= 0; i--) {
        if (dt.heSo[i] == 0) continue; // bỏ hệ số = 0

        // in dấu
        if (coIn) {
            if (dt.heSo[i] > 0) out << " + ";
            else out << " - ";
        }
        else {
            if (dt.heSo[i] < 0) out << "-";
        }

        double giaTri = dt.heSo[i];
        if (giaTri < 0) giaTri = -giaTri;

        // in hệ số (trừ trường hợp =1 và có x)
        if (!(giaTri == 1 && i != 0))
            out << giaTri;

          // in biến x
        if (i >= 1) out << "x";
        if (i >= 2) out << "^" << i;

        coIn = true;
    }
    
    // nếu toàn bộ = 0
    if (!coIn)
        out << "0";

    return out;
}