/*1. Xem danh sách;
  2. Thêm 1 chiếc xe;
  3. Tìm kiếm xe;
  4. Xóa 1 chiếc xe;
  5. Lưu tập tin;
  6. Đọc tập tin;
  7. Cập nhật thông tin xe;
  8. Thống kê xe theo nhãn hiệu : Toyota : 3, Yamaha : 2;*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Username {
	int id;
	string name;
	friend istream& operator>>(istream& in, Username& a) {
		cout << "Username information:" << endl;
		cout << "\t+ Id: ";
		in >> a.id;
		cout << "\t+ Name: ";
		in.ignore();
		getline(in, a.name);
		return in;
	}
};

struct Vehicle {
	int id;
	char type[30];
	string branch;
	double price;
	Username username;
	friend ostream& operator<<(ostream& os, const Vehicle& b) {
		os << "Vehicle information:" << endl;
		os << "\t+ Id: " << b.id << endl;
		os << "\t+ Branch: " << b.branch << endl;
		os << "\t+ Price: " << b.price << endl;
		os << "\t+ Username: " << b.username.name << endl;
		return os;
	}
	friend istream& operator>>(istream& in, Vehicle& b) {
		cout << "Vehicle information:" << endl;
		cout << "\t+ Id: ";
		in >> b.id;
		cout << "\t+ Type: ";
		in >> b.type;
		cout << "\t+ Branch: ";
		in.ignore();
		getline(in, b.branch);
		cout << "\t+ Price:";
		in >> b.price;
		in >> b.username;
		return in;
	}
};

template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
struct LinkedList {
	Node<T>* head = nullptr;
	void Show();
	void Add(T item);
	void Find(string branchName);
	bool Remove(int id);
	void Export(string fileName);
	void Import(string fileName);
	bool Update(int id);
	void Statistics();

template <typename T>
void LinkedList<T>::Show() {
	if (!head) {
		cout << "No vehicle available" << endl;
		return;
	}
	Node<T>* item = head;
	while (item) {
		cout << item->data;
		item = item->next;
	}
}
template <typename T>	 
void LinkedList<T>::Add(T item) {
	Node<T>* newNode = new Node<T>;
	newNode->data = item;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
	}
	else {
		Node<T>* item = head;
		while (item->next != nullptr) {
			item = item->next;
		}
		item->next = newNode;
	}
}

template<typename T>
void LinkedList <T>::Find(string branchName) {

	int main()
	{
		LinkedList books = { NULL };
		do {
			system("cls");
			cout << "-------- BOOK MANAGEMENT ---------" << endl;
			cout << "1. Show all books" << endl;
			cout << "2. Add a book" << endl;
			cout << "3. Delete a book" << endl;
			cout << "4. Update a book" << endl;
			cout << "5. Find book" << endl;
			cout << "6. Export to file" << endl;
			cout << "7. Import from file" << endl;
			cout << "0. Exit" << endl;
			cout << "----------------------------------" << endl;
			cout << "Enter your choice: ";
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1: {
				books.Show();
				break;
			}
			case 2: {
				Book b;
				cin >> b;
				Node* newNode = new Node;
				newNode->Create(b);
				books.AddFirst(newNode);
				break;
			}
			case 3: {
				int removeId;
				cout << "Enter book's id to remove: ";
				cin >> removeId;
				bool res = books.Remove(removeId);
				if (res)
					cout << "Remove book successfully" << endl;
				else
					cout << "Invalid book id" << endl;
				break;
			}
			case 4:
			{
				int updateId;
				cout << "Enter book's id to update: ";
				cin >> updateId;
				bool res = books.Update(updateId);
				if (res)
					cout << "Update book successfully" << endl;
				else
					cout << "Invalid book id" << endl;
				break;
			}
			case 5: {
				string bookName;
				cout << "Enter book's name to find: ";
				cin.ignore();
				getline(cin, bookName);
				Book* res = books.Find(bookName);
				if (res != NULL) {
					cout << *res;
				}
				else {
					cout << "No book with name: " << bookName << endl;
				}
				break;
			}
			case 6: {
				books.Export("25TH1.dla");
				cout << "Exported successfully" << endl;
				break;
			}
			case 7: {
				books.Import("25TH1.dla");
				break;
			}
			case 0: {
				return 0;
			}
			default: {
				cout << "Invalid choice, try again" << endl;
				break;
			}
			}
			system("pause");
			cout << "Press any key to continue.....";


		} while (true);
	}
