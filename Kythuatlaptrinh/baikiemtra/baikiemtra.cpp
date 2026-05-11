#include <stdio.h>
#include <string.h>

#define MAX 100

// Khai báo c?u trúc sinh viên
struct SinhVien {
    char maSV[20];
    char hoTen[50];
    float chuyenCan;
    float giuaKy;
    float cuoiKy;
    float diemHP;
};

// Hàm tính ?i?m h?c ph?n
float tinhDiemHP(float cc, float gk, float ck) {
    return cc * 0.1 + gk * 0.3 + ck * 0.6;
}

// Hàm nh?p danh sách sinh viên
void nhapDanhSach(struct SinhVien ds[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d\n", i + 1);

        printf("Ma sinh vien: ");
        scanf("%s", ds[i].maSV);

        printf("Ho ten: ");
        getchar(); // xóa ký t? Enter
        gets(ds[i].hoTen);

        printf("Diem chuyen can: ");
        scanf("%f", &ds[i].chuyenCan);

        printf("Diem giua ky: ");
        scanf("%f", &ds[i].giuaKy);

        printf("Diem cuoi ky: ");
        scanf("%f", &ds[i].cuoiKy);

        // Tính ?i?m h?c ph?n
        ds[i].diemHP = tinhDiemHP(
            ds[i].chuyenCan,
            ds[i].giuaKy,
            ds[i].cuoiKy
        );
    }
}

// Hàm xu?t danh sách
void xuatDanhSach(struct SinhVien ds[], int n) {
    int i;

    printf("\n===== DANH SACH SINH VIEN =====\n");

    for (i = 0; i < n; i++) {
        printf("\nMa SV: %s", ds[i].maSV);
        printf("\nHo ten: %s", ds[i].hoTen);
        printf("\nDiem hoc phan: %.2f\n", ds[i].diemHP);
    }
}

// S?p x?p gi?m d?n theo ?i?m h?c ph?n
void sapXep(struct SinhVien ds[], int n) {
    int i, j;
    struct SinhVien temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ds[i].diemHP < ds[j].diemHP) {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// S?p x?p t?ng d?n theo mã sinh viên
void sapXepMaSV(struct SinhVien ds[], int n) {
    int i, j;
    struct SinhVien temp;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(ds[i].maSV, ds[j].maSV) > 0) {
                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// Tìm ki?m nh? phân
int timKiemNhiPhan(struct SinhVien ds[], int n, char x[]) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        int kq = strcmp(ds[mid].maSV, x);

        if (kq == 0) {
            return mid;
        }
        else if (kq < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    struct SinhVien ds[MAX];
    int n;
    int viTri;
    char maCanTim[20];

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    // Nh?p danh sách
    nhapDanhSach(ds, n);

    // S?p x?p theo ?i?m h?c ph?n gi?m d?n
    sapXep(ds, n);

    printf("\nDanh sach sau khi sap xep theo diem hoc phan:\n");
    xuatDanhSach(ds, n);

    // S?p x?p theo mã SV ?? tìm ki?m nh? phân
    sapXepMaSV(ds, n);

    // Tìm ki?m
    printf("\nNhap ma sinh vien can tim: ");
    scanf("%s", maCanTim);

    viTri = timKiemNhiPhan(ds, n, maCanTim);

    if (viTri != -1) {
        printf("\nTim thay sinh vien:\n");
        printf("Ma SV: %s\n", ds[viTri].maSV);
        printf("Ho ten: %s\n", ds[viTri].hoTen);
        printf("Diem hoc phan: %.2f\n", ds[viTri].diemHP);
    }
    else {
        printf("\nKhong tim thay sinh vien!\n");
    }

    return 0;
}