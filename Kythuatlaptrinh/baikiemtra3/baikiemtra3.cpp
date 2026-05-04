
#include <iostream>
#include <string>


using namespace std;

// 1. Tách họ tên
void tachHoTen() {
    cin.ignore();
    string s;
    cout << "Nhap ho va ten: ";
    getline(cin, s);

    string ho = "", ten = "", lot = "";
    int pos1 = s.find(' ');
    int pos2 = s.rfind(' ');

    if (pos1 == string::npos) {
        cout << "Chuoi khong hop le!\n";
        return;
    }

    ho = s.substr(0, pos1);
    ten = s.substr(pos2 + 1);

    if (pos1 != pos2)
        lot = s.substr(pos1 + 1, pos2 - pos1 - 1);

    cout << "Ho: " << ho << endl;
    cout << "Ten lot: " << lot << endl;
    cout << "Ten: " << ten << endl;
}

// 2. Xóa ký tự
void xoaKyTu() {
    cin.ignore();
    string s;
    char x;

    cout << "Nhap chuoi: ";
    getline(cin, s);

    cout << "Nhap ky tu can xoa: ";
    cin >> x;

    string result = "";
    for (char c : s) {
        if (c != x) result += c;
    }

    cout << "Chuoi sau khi xoa: " << result << endl;
}

// 3. Kiểm tra đối xứng
void doiXung() {
    cin.ignore();
    string s;

    cout << "Nhap chuoi: ";
    getline(cin, s);

    string rev = s;
    reverse(rev.begin(), rev.end());

    if (s == rev)
        cout << "Chuoi doi xung" << endl;
    else
        cout << "Khong doi xung" << endl;
}

// 4. Tìm vị trí xuất hiện cuối cùng
void viTriCuoi() {
    cin.ignore();
    string x;
    char y;

    cout << "Nhap chuoi X: ";
    getline(cin, x);

    cout << "Nhap ky tu Y: ";
    cin >> y;

    size_t pos = x.rfind(y);

    if (pos == string::npos)
        cout << "Khong tim thay ky tu" << endl;
    else
        cout << "Vi tri cuoi cung: " << pos << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tach ho ten\n";
        cout << "2. Xoa ky tu trong chuoi\n";
        cout << "3. Kiem tra chuoi doi xung\n";
        cout << "4. Tim vi tri xuat hien cuoi cung\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1: tachHoTen(); break;
        case 2: xoaKyTu(); break;
        case 3: doiXung(); break;
        case 4: viTriCuoi(); break;
        case 0: cout << "Thoat chuong trinh!\n"; break;
        default: cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}