#include "Time.h"
#include <string>
using namespace std;

/*
Đầu vào:
    str: chuỗi cần kiểm tra
Đầu ra:
    true: nếu chuỗi là số nguyên dương hợp lệ
    false: nếu chuỗi rỗng hoặc chứa ký tự không hợp lệ
Ý tưởng:
    - Kiểm tra chuỗi rỗng
    - Duyệt từng ký tự
    - Nếu tất cả đều là chữ số thì hợp lệ
*/
bool laSoNguyenDuong(string str) {
    if (str.empty()) return false;

    for (int i = 0; i < (int)str.length(); i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

/*
Đầu vào:
    Không có
Đầu ra:
    Khởi tạo thời điểm mặc định 00:00:00
Ý tưởng:
    Gán giờ, phút, giây bằng 0
*/
Time::Time() {
    gio = 0;
    phut = 0;
    giay = 0;
}

/*
Đầu vào:
    g: giờ
    p: phút
    s: giây
Đầu ra:
    Tạo đối tượng Time với giá trị truyền vào
Ý tưởng:
    Gán tham số vào thuộc tính tương ứng
*/
Time::Time(int g, int p, int s) {
    gio = g;
    phut = p;
    giay = s;
}

/*
Đầu vào:
    Không có
Đầu ra:
    Hủy đối tượng
Ý tưởng:
    Không cần xử lý vì không cấp phát động
*/
Time::~Time() {
}

/*
Đầu vào:
    g: giờ
    p: phút
    s: giây
Đầu ra:
    Cập nhật lại thời điểm
Ý tưởng:
    Gán lại giá trị cho giờ, phút, giây
*/
void Time::set(int g, int p, int s) {
    gio = g;
    phut = p;
    giay = s;
}

/*
Đầu vào:
    soGiay: số giây cần cộng
Đầu ra:
    Một đối tượng Time mới sau khi cộng thêm số giây
Ý tưởng:
    - Sao chép thời điểm hiện tại
    - Tăng từng giây
    - Nếu giây = 60 thì tăng phút
    - Nếu phút = 60 thì tăng giờ
    - Nếu giờ = 24 thì quay về 0
*/
Time Time::operator+(int soGiay) {
    Time kq = *this;

    for (int i = 0; i < soGiay; i++) {
        kq.giay++;

        if (kq.giay == 60) {
            kq.giay = 0;
            kq.phut++;

            if (kq.phut == 60) {
                kq.phut = 0;
                kq.gio++;

                if (kq.gio == 24)
                    kq.gio = 0;
            }
        }
    }

    return kq;
}

/*
Đầu vào:
    Không có
Đầu ra:
    Thời điểm hiện tại tăng thêm 1 giây
Ý tưởng:
    - Tăng giây
    - Nếu giây = 60 thì tăng phút
    - Nếu phút = 60 thì tăng giờ
    - Nếu giờ = 24 thì quay về 0
*/
Time& Time::operator++() {
    giay++;

    if (giay == 60) {
        giay = 0;
        phut++;

        if (phut == 60) {
            phut = 0;
            gio++;

            if (gio == 24)
                gio = 0;
        }
    }

    return *this;
}

/*
Đầu vào:
    soGiay: số giây cần trừ
Đầu ra:
    Một đối tượng Time mới sau khi trừ số giây
Ý tưởng:
    - Sao chép thời điểm hiện tại
    - Giảm từng giây
    - Nếu giây < 0 thì mượn phút
    - Nếu phút < 0 thì mượn giờ
    - Nếu giờ < 0 thì quay về 23
*/
Time Time::operator-(int soGiay) {
    Time kq = *this;

    for (int i = 0; i < soGiay; i++) {
        kq.giay--;

        if (kq.giay < 0) {
            kq.giay = 59;
            kq.phut--;

            if (kq.phut < 0) {
                kq.phut = 59;
                kq.gio--;

                if (kq.gio < 0)
                    kq.gio = 23;
            }
        }
    }

    return kq;
}


/*
Đầu vào:
    Không có
Đầu ra:
    Thời điểm hiện tại giảm đi 1 giây
Ý tưởng:
    - Giảm giây
    - Nếu giây < 0 thì mượn phút
    - Nếu phút < 0 thì mượn giờ
    - Nếu giờ < 0 thì quay về 23
*/
Time& Time::operator--() {
    giay--;

    if (giay < 0) {
        giay = 59;
        phut--;

        if (phut < 0) {
            phut = 59;
            gio--;

            if (gio < 0)
                gio = 23;
        }
    }

    return *this;
}

/*
Đầu vào:
    Nhập vào giờ, phút, giây
Đầu ra:
    Một đối tượng Time hợp lệ
Ý tưởng:
    - Nhập từng thành phần dưới dạng chuỗi
    - Kiểm tra chuỗi có phải số nguyên dương không
    - Kiểm tra giá trị hợp lệ
    - Nhập lại nếu sai
*/
istream& operator>>(istream& in, Time& t) {
    string input;

    while (true) {
        cout << "Nhap gio: ";
        in >> input;

        if (!laSoNguyenDuong(input)) {
            cout << "Loi! Khong duoc nhap chu, ky hieu.\n";
        }
        else {
            t.gio = stoi(input);

            if (t.gio > 23)
                cout << "Gio phai tu 0 den 23.\n";
            else break;
        }
    }

    while (true) {
        cout << "Nhap phut: ";
        in >> input;

        if (!laSoNguyenDuong(input)) {
            cout << "Loi! Khong duoc nhap chu, ky hieu.\n";
        }
        else {
            t.phut = stoi(input);

            if (t.phut > 59)
                cout << "Phut phai tu 0 den 59.\n";
            else break;
        }
    }

    while (true) {
        cout << "Nhap giay: ";
        in >> input;

        if (!laSoNguyenDuong(input)) {
            cout << "Loi! Khong duoc nhap chu, ky hieu.\n";
        }
        else {
            t.giay = stoi(input);

            if (t.giay > 59)
                cout << "Giay phai tu 0 den 59.\n";
            else break;
        }
    }

    return in;
}

/*
Đầu vào:
    t: đối tượng Time
Đầu ra:
    Xuất thời gian theo định dạng hh:mm:ss
Ý tưởng:
    - Nếu giờ/phút/giây < 10 thì thêm số 0 phía trước
    - Xuất theo định dạng chuẩn
*/
ostream& operator<<(ostream& out, const Time& t) {
    if (t.gio < 10) out << "0";
    out << t.gio << ":";

    if (t.phut < 10) out << "0";
    out << t.phut << ":";

    if (t.giay < 10) out << "0";
    out << t.giay;

    return out;
}