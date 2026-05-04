#include <iostream>
#include <vector>

using namespace std;

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	cout << "Duyet mang bang con tro:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "Phan tu" << i << " *(p + i) = " << *(p + i) << " | p[i] = " << p[i] << endl;
	}
	vector<int> v;
	int n_vec, value;
	cout << "Nhap so luong phan tu n :";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "nhap phan tu thu" << i + 1 << ": ";
		cin >> value;
		v.push_back(value);
	}
	cout << "cac phan tu trong vector: ";
	for (int x : v) {
		cout << x << " ";
	}
	cout << "Nhap phan tu muon them vao cuoi: ";
	cin >> value;
	v.push_back(value);
	if (!v.empty()) {
		v.pop_back();
		cout << "Da xoa phan tu cuoi cung: ";
	}
	cout << "\nVector hien tai: ";
	for (int x : v) cout << x << " ";

	return 0;
}
