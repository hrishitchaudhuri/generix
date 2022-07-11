#include<iostream>

#include "list.h"

Node& operator+(const Node& rhs, const Node& lhs) {
	return Node(rhs.val_ + lhs.val_);
}

std::ostream& operator<<(std::ostream& o, const Node& n){
	return o << n.val_;
}

void List::append(int p) {
	if (head_ == nullptr) {
		head_ = tail_ = new Node(p);
	}

	else {
		tail_->next_ = new Node(p);
		tail_ = tail_->next_;
	}
}