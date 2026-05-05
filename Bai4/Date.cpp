#include "Date.h"
#include <string>

using namespace std;

/* laSoNguyenDuong
Đầu vào:
    - s: chuỗi ký tự cần kiểm tra
Đầu ra:
    - true: nếu chuỗi chỉ chứa chữ số từ 0 đến 9
    - false: nếu chuỗi rỗng hoặc chứa ký tự không hợp lệ
Hướng giải thuật:
    - Nếu chuỗi rỗng -> trả về false
    - Duyệt từng ký tự trong chuỗi
    - Nếu tồn tại ký tự không phải chữ số -> false
    - Ngược lại -> true
*/
bool laSoNguyenDuong(string s) {
    if (s.empty()) return false;

    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    return true;
}

/* laNamNhuan
Đầu vào:
    - nam: năm cần kiểm tra
Đầu ra:
    - true: nếu là năm nhuận
    - false: nếu không phải năm nhuận
Hướng giải thuật:
    - Nếu chia hết cho 400 -> năm nhuận
    - Nếu chia hết cho 4 và không chia hết cho 100 -> năm nhuận
    - Ngược lại -> không nhuận
*/
bool laNamNhuan(int nam) {
    if (nam % 400 == 0) return true;
    if (nam % 4 == 0 && nam % 100 != 0) return true;
    return false;
}

/* soNgayTrongThang
Đầu vào:
    - thang: tháng
    - nam: năm
Đầu ra:
    - số ngày của tháng tương ứng
Hướng giải thuật:
    - Xét từng nhóm tháng có 31 ngày
    - Xét từng nhóm tháng có 30 ngày
    - Tháng 2 kiểm tra năm nhuận
*/
int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;

        case 4: case 6: case 9: case 11:
            return 30;

        case 2:
            return laNamNhuan(nam) ? 29 : 28;
    }

    return 0;
}

/*
Đầu vào:
    - Không có
Đầu ra:
    - Khởi tạo ngày mặc định 1/1/1
Hướng giải thuật:
    - Gán ngày = 1, tháng = 1, năm = 1
*/
Date::Date() {
    ngay = 1;
    thang = 1;
    nam = 1;
}

/*
Đầu vào:
    - n: ngày
    - t: tháng
    - y: năm
Đầu ra:
    - Khởi tạo đối tượng Date với giá trị truyền vào
Hướng giải thuật:
    - Gán trực tiếp các giá trị vào thuộc tính
*/
Date::Date(int n, int t, int y) {
    ngay = n;
    thang = t;
    nam = y;
}

/*
Đầu vào:
    - Không có
Đầu ra:
    - Hủy đối tượng Date
Hướng giải thuật:
    - Không cần xử lý vì không cấp phát động
*/
Date::~Date() {
}

/*
Đầu vào:
    - n: ngày
    - t: tháng
    - y: năm
Đầu ra:
    - Cập nhật lại giá trị cho đối tượng Date
Hướng giải thuật:
    - Gán trực tiếp giá trị mới
*/
void Date::set(int n, int t, int y) {
    ngay = n;
    thang = t;
    nam = y;
}

/*
Đầu vào:
    - Không có (sử dụng dữ liệu hiện tại của đối tượng)
Đầu ra:
    - true: nếu ngày hợp lệ
    - false: nếu ngày không hợp lệ
Hướng giải thuật:
    - Kiểm tra tháng phải từ 1 đến 12
    - Lấy số ngày tối đa của tháng
    - Kiểm tra ngày thuộc khoảng hợp lệ
*/
bool Date::kiemTraNgayHopLe() {
    if (thang < 1 || thang > 12)
        return false;

    int soNgay = soNgayTrongThang(thang, nam);

    if (ngay < 1 || ngay > soNgay)
        return false;

    return true;
}

/*
Đầu vào:
    - soNgay: số ngày cần cộng
Đầu ra:
    - đối tượng Date mới sau khi cộng
Hướng giải thuật:
    - Tăng từng ngày
    - Nếu vượt số ngày trong tháng -> reset ngày, tăng tháng
    - Nếu tháng vượt 12 -> reset tháng, tăng năm
*/
Date Date::operator+(int soNgay) {
    Date kq = *this;

    for (int i = 0; i < soNgay; i++) {
        kq.ngay++;

        if (kq.ngay > soNgayTrongThang(kq.thang, kq.nam)) {
            kq.ngay = 1;
            kq.thang++;

            if (kq.thang > 12) {
                kq.thang = 1;
                kq.nam++;
            }
        }
    }

    return kq;
}

/*
Đầu vào:
    - soNgay: số ngày cần trừ
Đầu ra:
    - đối tượng Date mới sau khi trừ
Hướng giải thuật:
    - Giảm từng ngày
    - Nếu ngày < 1 -> lùi tháng
    - Nếu tháng < 1 -> lùi năm
*/
Date Date::operator-(int soNgay) {
    Date kq = *this;

    for (int i = 0; i < soNgay; i++) {
        kq.ngay--;

        if (kq.ngay < 1) {
            kq.thang--;

            if (kq.thang < 1) {
                kq.thang = 12;
                kq.nam--;
            }

            kq.ngay = soNgayTrongThang(kq.thang, kq.nam);
        }
    }

    return kq;
}

/*
Đầu vào:
    - ngayKhac: đối tượng Date cần so sánh khoảng cách
Đầu ra:
    - số ngày chênh lệch giữa hai ngày
Hướng giải thuật:
    - So sánh hai ngày
    - Lùi từng ngày của ngày lớn hơn
    - Đếm số lần lùi đến khi bằng nhau
*/
int Date::operator-(const Date& ngayKhac) {
    Date a = *this;
    Date b = ngayKhac;

    int dem = 0;

    while (!(a.ngay == b.ngay &&
             a.thang == b.thang &&
             a.nam == b.nam)) {

        if (a.nam > b.nam ||
            (a.nam == b.nam && a.thang > b.thang) ||
            (a.nam == b.nam && a.thang == b.thang && a.ngay > b.ngay)) {
            --a;
        }
        else {
            --b;
        }

        dem++;
    }

    return dem;
}

/*
Đầu vào:
    - Không có
Đầu ra:
    - tăng thêm 1 ngày
Hướng giải thuật:
    - Gọi lại operator+ với 1 ngày
*/
Date& Date::operator++() {
    *this = *this + 1;
    return *this;
}

/*
Đầu vào:
    - Không có
Đầu ra:
    - giảm đi 1 ngày
Hướng giải thuật:
    - Gọi lại operator- với 1 ngày
*/
Date& Date::operator--() {
    *this = *this - 1;
    return *this;
}

/*
Đầu vào:
    - luồng nhập
    - đối tượng Date
Đầu ra:
    - nhập vào một ngày hợp lệ
Hướng giải thuật:
    - Nhập ngày, tháng, năm dưới dạng chuỗi
    - Kiểm tra số nguyên dương
    - Kiểm tra giới hạn ngày, tháng
    - Kiểm tra ngày hợp lệ
*/
istream& operator>>(istream& in, Date& d) {
    string input;

    do {
        // nhập ngày
        while (true) {
            cout << "Nhap ngay: ";
            in >> input;

            if (laSoNguyenDuong(input)) {
                int ngay = stoi(input);

                if (ngay >= 1 && ngay <= 31) {
                    d.ngay = ngay;
                    break;
                }
            }

            cout << "Loi! Ngay phai tu 1 den 31. Nhap lai.\n";
        }

        // nhập tháng
        while (true) {
            cout << "Nhap thang: ";
            in >> input;

            if (laSoNguyenDuong(input)) {
                int thang = stoi(input);

                if (thang >= 1 && thang <= 12) {
                    d.thang = thang;
                    break;
                }
            }

            cout << "Loi! Thang phai tu 1 den 12. Nhap lai.\n";
        }

        // nhập năm
        while (true) {
            cout << "Nhap nam: ";
            in >> input;

            if (laSoNguyenDuong(input)) {
                d.nam = stoi(input);
                break;
            }

            cout << "Loi! Nam phai la so nguyen duong. Nhap lai.\n";
        }

        if (!d.kiemTraNgayHopLe())
            cout << "Ngay khong hop le! Nhap lai.\n";

    } while (!d.kiemTraNgayHopLe());

    return in;
}

/*
Đầu vào:
    - luồng xuất
    - đối tượng Date
Đầu ra:
    - xuất ngày theo dạng ngay/thang/nam
Hướng giải thuật:
    - Xuất trực tiếp từng thành phần
*/
ostream& operator<<(ostream& out, const Date& d) {
    out << d.ngay << "/" << d.thang << "/" << d.nam;
    return out;
}