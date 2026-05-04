#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct ThietBi {
    char maSo[20];
    char tenThietBi[50];
    int soNamBaoHanh;
    int namMua;
};

struct Node {
    ThietBi data;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

// Khởi tạo
void init(Queue& q) {
    q.front = q.rear = NULL;
}

// Kiểm tra rỗng
bool isEmpty(Queue q) {
    return q.front == NULL;
}

// Thêm thiết bị
void enqueue(Queue& q, ThietBi tb) {
    Node* p = new Node;
    p->data = tb;
    p->next = NULL;

    if (q.rear == NULL) {
        q.front = q.rear = p;
    }
    else {
        q.rear->next = p;
        q.rear = p;
    }
}

// Xóa thiết bị
bool dequeue(Queue& q, ThietBi& tb) {
    if (isEmpty(q)) return false;

    Node* p = q.front;
    tb = p->data;
    q.front = q.front->next;

    if (q.front == NULL) q.rear = NULL;

    delete p;
    return true;
}

// Hiển thị danh sách
void hienThi(Queue q) {
    if (isEmpty(q)) {
        cout << "Danh sach rong!\n";
        return;
    }

    Node* p = q.front;
    while (p != NULL) {
        cout << p->data.maSo << " | "
            << p->data.tenThietBi << " | "
            << p->data.soNamBaoHanh << " nam | "
            << p->data.namMua << endl;
        p = p->next;
    }
}

// Nhập thiết bị
ThietBi nhap() {
    ThietBi tb;
    cout << "Ma so: "; cin.ignore(); cin.getline(tb.maSo, 20);
    cout << "Ten thiet bi: "; cin.getline(tb.tenThietBi, 50);
    cout << "So nam bao hanh: "; cin >> tb.soNamBaoHanh;
    cout << "Nam mua: "; cin >> tb.namMua;
    return tb;
}

// Thiết bị hết bảo hành
void hetBaoHanh(Queue q) {
    int namHienTai = 2026;
    bool found = false;

    Node* p = q.front;
    while (p != NULL) {
        if (p->data.namMua + p->data.soNamBaoHanh <= namHienTai) {
            cout << p->data.maSo << " | "
                << p->data.tenThietBi << endl;
            found = true;
        }
        p = p->next;
    }

    if (!found) cout << "Khong co thiet bi het bao hanh!\n";
}

// Ghi file
void ghiFile(Queue q, const char* tenFile) {
    ofstream f(tenFile, ios::binary);

    Node* p = q.front;
    while (p != NULL) {
        f.write((char*)&p->data, sizeof(ThietBi));
        p = p->next;
    }

    f.close();
    cout << "Da ghi file!\n";
}

// Đọc file
void docFile(Queue& q, const char* tenFile) {
    ifstream f(tenFile, ios::binary);
    ThietBi tb;

    while (f.read((char*)&tb, sizeof(ThietBi))) {
        enqueue(q, tb);
    }

    f.close();
    cout << "Da doc file!\n";
}

// Menu
void menu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Hien thi danh sach\n";
    cout << "2. Them thiet bi\n";
    cout << "3. Xoa thiet bi\n";
    cout << "4. Thiet bi het bao hanh\n";
    cout << "5. Ghi file\n";
    cout << "6. Doc file\n";
    cout << "0. Thoat\n";
}

int main() {
    Queue q;
    init(q);

    int chon;
    ThietBi tb;

    do {
        menu();
        cout << "Chon: ";
        cin >> chon;

        switch (chon) {
        case 1:
            hienThi(q);
            break;

        case 2:
            tb = nhap();
            enqueue(q, tb);
            break;

        case 3:
            if (dequeue(q, tb))
                cout << "Da xoa: " << tb.tenThietBi << endl;
            else
                cout << "Danh sach rong!\n";
            break;

        case 4:
            hetBaoHanh(q);
            break;

        case 5:
            ghiFile(q, "thietbi.dat");
            break;

        case 6:
            docFile(q, "thietbi.dat");
            break;
        }

    } while (chon != 0);

    return 0;
}