#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Term {
	int coeff_;
	int expo_;
};

void diff(const list<Term>& src, list<Term>& dest) {
	auto first = begin(src);
	auto last = end(src);
	
	Term temp;
	
	while (first != last) {
		temp;
		
		if ((*first).expo_ > 0) {
			temp.coeff_ = (*first).coeff_ * (*first).expo_;
			temp.expo_ = ((*first).expo_ - 1);
		}
		
		else {
			temp.coeff_ = 0;
			temp.expo_ = 0;
		}
		
		dest.push_front(temp);
		
		++first;
	}
}

int main() {
	list<Term> s;
	
	Term t1;
	Term t2;
	Term t3;
	
	t1.coeff_ = 3;
	t1.expo_ = 2;
	
	t2.coeff_ = 4;
	t2.expo_ = 3;
	
	t3.coeff_ = 2;
	t3.expo_ = 0;
	
	s.push_front(t1);
	s.push_front(t2);
	s.push_front(t3);
	
	list<Term> d;
	
	diff(s, d);
	
	for (auto e: d) {
		cout << e.coeff_ << " " << e.expo_ << "\n";
	}

	return 0;
}
