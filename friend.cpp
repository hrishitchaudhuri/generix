#include<iostream>

class Node;

class List {
	Node* head_;

	public:
		List();
		void add(int);
		void disp() const;
};

class Node {
	int key_;
	Node* link_;
	Node(int key)
	: key_(key), link_(nullptr) {}

	friend class List;
};

List::List()
: head_(nullptr) {}

void List::add(int key) {
	Node *temp = new Node(key);
	temp->link_ = head_;
	head_ = temp;
}
