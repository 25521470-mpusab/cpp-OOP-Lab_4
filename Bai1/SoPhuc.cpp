#include "SoPhuc.h"

const double EPS = 1e-9;

/*
Input: một số thực x
Output: trị tuyệt đối của x
Ý tưởng:
- Nếu x âm thì đổi dấu
- Nếu x không âm thì giữ nguyên
*/
double TriTuyetDoi(double x) {
    return (x < 0) ? -x : x;
}

/*
Input: không có
Output: khởi tạo số phức mặc định 0 + 0i
Ý tưởng:
- Gán phần thực và phần ảo bằng 0
*/
SoPhuc::SoPhuc() {
    thuc = 0;
    ao = 0;
}

/*
Input:
- t: phần thực
- a: phần ảo
Output:
- tạo số phức với giá trị tương ứng
Ý tưởng:
- Gán trực tiếp giá trị vào thuộc tính
*/
SoPhuc::SoPhuc(double t, double a) {
    thuc = t;
    ao = a;
}

/*
Input: không có
Output: hủy đối tượng số phức
Ý tưởng:
- Không cần giải phóng tài nguyên đặc biệt
*/
SoPhuc::~SoPhuc() {
}

/*
Input:
- t: phần thực mới
- a: phần ảo mới
Output:
- cập nhật lại giá trị số phức
Ý tưởng:
- Gán lại giá trị mới cho thuộc tính
*/
void SoPhuc::set(double t, double a) {
    thuc = t;
    ao = a;
}

/*
Input:
- b: số phức cần cộng
Output:
- số phức là tổng của hai số phức
Ý tưởng:
- Cộng phần thực với phần thực
- Cộng phần ảo với phần ảo
*/
SoPhuc SoPhuc::operator + (const SoPhuc &b) {
    return SoPhuc(thuc + b.thuc, ao + b.ao);
}

/*
Input:
- b: số phức cần trừ
Output:
- số phức là hiệu của hai số phức
Ý tưởng:
- Trừ phần thực
- Trừ phần ảo
*/
SoPhuc SoPhuc::operator - (const SoPhuc &b) {
    return SoPhuc(thuc - b.thuc, ao - b.ao);
}

/*
Input:
- b: số phức cần nhân
Output:
- số phức là tích của hai số phức
Ý tưởng:
- Áp dụng công thức nhân số phức:
(a+bi)(c+di)=(ac-bd)+(ad+bc)i
*/
SoPhuc SoPhuc::operator * (const SoPhuc &b) {
    return SoPhuc(
        thuc * b.thuc - ao * b.ao,
        thuc * b.ao + ao * b.thuc
    );
}

/*
Input:
- b: số phức cần chia
Output:
- thương của hai số phức
Ý tưởng:
- Tính mẫu số c²+d²
- Nếu mẫu bằng 0 thì báo lỗi
- Áp dụng công thức chia số phức
*/
SoPhuc SoPhuc::operator / (const SoPhuc &b) {
    double mau = b.thuc * b.thuc + b.ao * b.ao;

    if (TriTuyetDoi(mau) < EPS) {
        cout << "Khong the chia cho 0!" << endl;
        return SoPhuc();
    }

    return SoPhuc(
        (thuc * b.thuc + ao * b.ao) / mau,
        (ao * b.thuc - thuc * b.ao) / mau
    );
}

/*
Input:
- b: số phức cần so sánh
Output:
- true nếu bằng nhau, false nếu khác
Ý tưởng:
- So sánh phần thực và phần ảo với sai số EPS
*/
bool SoPhuc::operator == (const SoPhuc &b) {
    return (TriTuyetDoi(thuc - b.thuc) < EPS &&
            TriTuyetDoi(ao - b.ao) < EPS);
}

/*
Input:
- b: số phức cần so sánh
Output:
- true nếu khác nhau, false nếu bằng nhau
Ý tưởng:
- Phủ định kết quả phép ==
*/
bool SoPhuc::operator != (const SoPhuc &b) {
    return !(*this == b);
}

/*
Input:
- out: luồng xuất
- a: số phức cần xuất
Output:
- xuất số phức ra màn hình
Ý tưởng:
- Xử lý các trường hợp đặc biệt:
+ cả thực và ảo bằng 0
+ chỉ có phần thực
+ chỉ có phần ảo
+ đầy đủ cả hai phần
*/
ostream& operator << (ostream &out, const SoPhuc &a) {
    if (TriTuyetDoi(a.thuc) < EPS && TriTuyetDoi(a.ao) < EPS) {
        out << 0;
    }
    else if (TriTuyetDoi(a.ao) < EPS) {
        out << a.thuc;
    }
    else if (TriTuyetDoi(a.thuc) < EPS) {
        out << a.ao << "i";
    }
    else {
        out << a.thuc;
        if (a.ao > 0)
            out << "+" << a.ao << "i";
        else
            out << a.ao << "i";
    }

    return out;
}

/*
Input:
- in: luồng nhập
- a: số phức cần nhập
Output:
- cập nhật giá trị số phức từ bàn phím
Ý tưởng:
- Nhập lần lượt phần thực và phần ảo
*/
istream& operator >> (istream &in, SoPhuc &a) {
    in >> a.thuc >> a.ao;
    return in;
}