template <typename T>
struct Node {
	T data;
	Node* next;
};

template <typename T>
struct LinkedList {
	Node<T>* head;
	void Show();
};

template <typename T>
void LinkedList<T>::Show() {
	if (head == NULL) {
		cout << "No item available" << endl;
		return;
	}
	Node<T>* item = head;
	while (item != NULL) {
		cout << item->data;
		item = item->next;
	}
}