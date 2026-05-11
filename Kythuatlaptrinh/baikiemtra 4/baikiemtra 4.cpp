#include <iostream>
using namespace std;

struct SinhVien {
    int maSV;
    string hoTen;
    float diemCC,diemGK,diemCK,diemHP;
};

float tinhDiemHP(SinhVien sv) {
    return sv.diemCC * 0.1 +
        sv.diemGK * 0.3 +
        sv.diemCK * 0.6;
}

int main() {

    SinhVien ds[100];
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        cout << "\nNhap sinh vien thu " << i + 1 << endl;

        cout << "Ma SV: ";
        cin >> ds[i].maSV;

        cin.ignore();

        cout << "Ho ten: ";
        cin >>ds[i].hoTen;

        cout << "Diem chuyen can: ";
        cin >> ds[i].diemCC;

        cout << "Diem giua ky: ";
        cin >> ds[i].diemGK;

        cout << "Diem cuoi ky: ";
        cin >> ds[i].diemCK;

        ds[i].diemHP = tinhDiemHP(ds[i]);
    }


    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (ds[i].diemHP < ds[j].diemHP) {

                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    cout << "\nDANH SACH SAU KHI SAP XEP:\n";

    for (int i = 0; i < n; i++) {

        cout << "\nMa SV: " << ds[i].maSV << endl;
        cout << "Ho ten: " << ds[i].hoTen << endl;
        cout << "Diem hoc phan: " << ds[i].diemHP << endl;
    }

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (ds[i].maSV > ds[j].maSV) {

                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    int x;

    cout << "\nNhap ma sinh vien can tim: ";
    cin >> x;

    int left = 0;
    int right = n - 1;
    int found = -1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (ds[mid].maSV == x) {
            found = mid;
            break;
        }

        else if (ds[mid].maSV < x) {
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }

    if (found != -1) {

        cout << "\nTIM THAY SINH VIEN\n";

        cout << "Ma SV: " << ds[found].maSV << endl;
        cout << "Ho ten: " << ds[found].hoTen << endl;
        cout << "Diem hoc phan: " << ds[found].diemHP << endl;
    }

    else {
        cout << "\nKhong tim thay sinh vien!";
    }

    return 0;
}
