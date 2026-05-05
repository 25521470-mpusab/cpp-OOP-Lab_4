#include "Matrix.h"

int main() {
    Matrix A, B;

    cout << "Nhap ma tran A:\n";
    cin >> A;

    cout << "\nNhap ma tran B:\n";
    cin >> B;

    cout << "\nMa tran A:\n";
    cout << A;

    cout << "\nMa tran B:\n";
    cout << B;

    cout << "\nTong A + B:\n";
    cout << A + B;

    cout << "\nHieu A - B:\n";
    cout << A - B;

    cout << "\nTich A * B:\n";
    cout << A * B;

    if (A.laMaTranVuong()) {
        cout << "\nDinh thuc A: "
             << A.tinhDinhThuc() << endl;
    }
    else {
        cout << "\nA khong phai ma tran vuong!\n";
    }

    if (B.laMaTranVuong()) {
        cout << "\nDinh thuc B: "
             << B.tinhDinhThuc() << endl;
    }
    else {
        cout << "\nB khong phai ma tran vuong!\n";
    }


    // nhập vector để nhân với A
    int n;

    do {
        cout << "\nNhap so chieu vector: ";
        cin >> n;

        if (n <= 0) {
            cout << "So chieu phai > 0!\n";
        }
        else if (n != A.getSoCot()) {
            cout << "So chieu vector phai bang "
                 << A.getSoCot() << endl;
        }

    } while (n <= 0 || n != A.getSoCot());

    double* v = new double[n];

    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "Nhap v[" << i << "]: ";
            cin >> v[i];

            if (cin.fail()) {
                cout << "Chi duoc nhap so!\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else break;
        }
    }


    // nhân A với vector
    double* kq = A.nhanVector(v, n);

    if (kq != NULL) {
        cout << "\nKet qua A * v:\n";

        for (int i = 0; i < A.getSoDong(); i++) {
            cout << kq[i] << " ";
        }

        cout << endl;

        delete[] kq;
    }

    delete[] v;

    return 0;
}