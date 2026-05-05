#include "Matrix.h"
#include <string>
#include <cmath>

using namespace std;

/*
Đầu vào:
    chuỗi ký tự
Đầu ra:
    true nếu là số nguyên dương
    false nếu không phải
Hướng giải thuật:
    duyệt từng ký tự
    kiểm tra có thuộc [0..9]
*/
bool laSoNguyenDuong(string s) {
    if (s.empty()) return false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    return true;
}

/*
Đầu vào:
    không có
Đầu ra:
    tạo ma trận mặc định 1x1 = 0
Hướng giải thuật:
    cấp phát ma trận 1x1
*/
Matrix::Matrix() {
    soDong = 1;
    soCot = 1;

    giaTri = new double*[soDong];

    for (int i = 0; i < soDong; i++) {
        giaTri[i] = new double[soCot];
        giaTri[i][0] = 0;
    }
}

/*
Đầu vào:
    số dòng, số cột
Đầu ra:
    tạo ma trận kích thước tương ứng
Hướng giải thuật:
    cấp phát động mảng 2 chiều
*/
Matrix::Matrix(int dong, int cot) {
    soDong = dong;
    soCot = cot;

    giaTri = new double*[soDong];

    for (int i = 0; i < soDong; i++) {
        giaTri[i] = new double[soCot];

        for (int j = 0; j < soCot; j++) {
            giaTri[i][j] = 0;
        }
    }
}

/*
Đầu vào:
    ma trận khác
Đầu ra:
    tạo bản sao 
Hướng giải thuật:
    copy toàn bộ dữ liệu
*/
Matrix::Matrix(const Matrix& m) {
    soDong = m.soDong;
    soCot = m.soCot;

    giaTri = new double*[soDong];

    for (int i = 0; i < soDong; i++) {
        giaTri[i] = new double[soCot];

        for (int j = 0; j < soCot; j++) {
            giaTri[i][j] = m.giaTri[i][j];
        }
    }
}

/*
Đầu vào:
    không có
Đầu ra:
    giải phóng bộ nhớ
Hướng giải thuật:
    delete từng dòng rồi delete mảng ngoài
*/
Matrix::~Matrix() {
    for (int i = 0; i < soDong; i++) {
        delete[] giaTri[i];
    }

    delete[] giaTri;
}

/*
Đầu vào:
    số dòng mới, số cột mới
Đầu ra:
    thiết lập lại ma trận
Hướng giải thuật:
    xóa ma trận cũ
    cấp phát ma trận mới
*/
void Matrix::set(int dong, int cot) {
    for (int i = 0; i < soDong; i++) {
        delete[] giaTri[i];
    }

    delete[] giaTri;

    soDong = dong;
    soCot = cot;

    giaTri = new double*[soDong];

    for (int i = 0; i < soDong; i++) {
        giaTri[i] = new double[soCot];

        for (int j = 0; j < soCot; j++) {
            giaTri[i][j] = 0;
        }
    }
}

/*
Đầu vào: không có
Đầu ra: số dòng
*/
int Matrix::getSoDong() const {
    return soDong;
}

/*
Đầu vào: không có
Đầu ra: số cột
*/
int Matrix::getSoCot() const {
    return soCot;
}

/*
Đầu vào:
    ma trận hiện tại
Đầu ra:
    true nếu là ma trận vuông
Hướng giải thuật:
    số dòng == số cột
*/
bool Matrix::laMaTranVuong() const {
    return soDong == soCot;
}

/*
Đầu vào:
    ma trận vuông
Đầu ra:
    định thức
Hướng giải thuật:
    khai triển công thức
*/
double Matrix::tinhDinhThuc() const {
    if (!laMaTranVuong()) {
        cout << "Khong phai ma tran vuong!\n";
        return 0;
    }

    if (soDong == 1)
        return giaTri[0][0];

    if (soDong == 2)
        return giaTri[0][0] * giaTri[1][1]
             - giaTri[0][1] * giaTri[1][0];

    double det = 0;

    for (int k = 0; k < soCot; k++) {
        Matrix con(soDong - 1, soCot - 1);

        for (int i = 1; i < soDong; i++) {
            int cotCon = 0;

            for (int j = 0; j < soCot; j++) {
                if (j == k) continue;

                con.giaTri[i - 1][cotCon] = giaTri[i][j];
                cotCon++;
            }
        }

        det += pow(-1, k) * giaTri[0][k] * con.tinhDinhThuc();
    }

    return det;
}

/*
Đầu vào:
    vector v, số chiều n
Đầu ra:
    vector kết quả
Điều kiện:
    số chiều vector = số cột ma trận
Hướng giải thuật:
    nhân từng dòng với vector
*/
double* Matrix::nhanVector(const double* v, int n) const {
    if (soCot != n) {
        cout << "Khong the nhan ma tran voi vector!\n";
        return NULL;
    }

    double* kq = new double[soDong];

    for (int i = 0; i < soDong; i++) {
        kq[i] = 0;

        for (int j = 0; j < soCot; j++) {
            kq[i] += giaTri[i][j] * v[j];
        }
    }

    return kq;
}

/*
Đầu vào:
    ma trận khác
Đầu ra:
    gán dữ liệu
Hướng giải thuật:
    deep copy
*/
Matrix& Matrix::operator=(const Matrix& m) {
    if (this == &m)
        return *this;

    set(m.soDong, m.soCot);

    for (int i = 0; i < soDong; i++) {
        for (int j = 0; j < soCot; j++) {
            giaTri[i][j] = m.giaTri[i][j];
        }
    }

    return *this;
}

/*
Đầu vào:
    2 ma trận cùng kích thước
Đầu ra:
    ma trận tổng
Hướng giải thuật:
    cộng từng phần tử tương ứng
*/
Matrix Matrix::operator+(const Matrix& m) const {
    if (soDong != m.soDong || soCot != m.soCot) {
        cout << "Khong cung kich thuoc!\n";
        return Matrix();
    }

    Matrix kq(soDong, soCot);

    for (int i = 0; i < soDong; i++)
        for (int j = 0; j < soCot; j++)
            kq.giaTri[i][j] = giaTri[i][j] + m.giaTri[i][j];

    return kq;
}

/*
Đầu vào:
    2 ma trận cùng kích thước
Đầu ra:
    ma trận hiệu
Hướng giải thuật:
    trừ từng phần tử
*/
Matrix Matrix::operator-(const Matrix& m) const {
    if (soDong != m.soDong || soCot != m.soCot) {
        cout << "Khong cung kich thuoc!\n";
        return Matrix();
    }

    Matrix kq(soDong, soCot);

    for (int i = 0; i < soDong; i++)
        for (int j = 0; j < soCot; j++)
            kq.giaTri[i][j] = giaTri[i][j] - m.giaTri[i][j];

    return kq;
}

/*
Đầu vào:
    2 ma trận
Đầu ra:
    tích 2 ma trận
Điều kiện:
    số cột A = số dòng B
Hướng giải thuật:
    nhân ma trận chuẩn
*/
Matrix Matrix::operator*(const Matrix& m) const {
    if (soCot != m.soDong) {
        cout << "Khong the nhan!\n";
        return Matrix();
    }

    Matrix kq(soDong, m.soCot);

    for (int i = 0; i < soDong; i++)
        for (int j = 0; j < m.soCot; j++)
            for (int k = 0; k < soCot; k++)
                kq.giaTri[i][j] += giaTri[i][k] * m.giaTri[k][j];

    return kq;
}

/*
Đầu vào:
    số dòng, số cột, các phần tử

Đầu ra:
    ma trận hợp lệ

Điều kiện:
    số dòng > 0
    số cột > 0
    phần tử phải là số

Hướng giải thuật:
    - nhập số dòng, kiểm tra hợp lệ
    - nhập số cột, kiểm tra hợp lệ
    - cấp phát lại ma trận
    - nhập từng phần tử và kiểm tra kiểu dữ liệu
*/
istream& operator>>(istream& in, Matrix& m) {
    string input;

    // nhập số dòng
    while (true) {
        cout << "Nhap so dong: ";
        in >> input;

        if (!laSoNguyenDuong(input)) {
            cout << "Loi! So dong phai la so nguyen duong.\n";
        }
        else {
            m.soDong = stoi(input);

            if (m.soDong <= 0) {
                cout << "So dong phai > 0.\n";
            }
            else break;
        }
    }

    // nhập số cột
    while (true) {
        cout << "Nhap so cot: ";
        in >> input;

        if (!laSoNguyenDuong(input)) {
            cout << "Loi! So cot phai la so nguyen duong.\n";
        }
        else {
            m.soCot = stoi(input);

            if (m.soCot <= 0) {
                cout << "So cot phai > 0.\n";
            }
            else break;
        }
    }

    // cấp phát lại ma trận
    m.set(m.soDong, m.soCot);

    // nhập từng phần tử
    for (int i = 0; i < m.soDong; i++) {
        for (int j = 0; j < m.soCot; j++) {
            while (true) {
                cout << "Nhap a[" << i << "][" << j << "]: ";
                in >> m.giaTri[i][j];

                if (in.fail()) {
                    cout << "Loi! Chi duoc nhap so.\n";
                    in.clear();
                    in.ignore(10000, '\n');
                }
                else {
                    break;
                }
            }
        }
    }

    return in;
}

/*
Đầu vào:
    ma trận
Đầu ra:
    xuất dạng bảng
Hướng giải thuật:
    duyệt từng dòng từng cột
*/
ostream& operator<<(ostream& out, const Matrix& m) {
    for (int i = 0; i < m.soDong; i++) {
        for (int j = 0; j < m.soCot; j++) {
            out << m.giaTri[i][j] << " ";
        }
        out << endl;
    }

    return out;
}