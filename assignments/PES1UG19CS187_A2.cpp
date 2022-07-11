#include<iostream>
#include<vector>

using namespace std;

template <typename iter>
class IteratorRange {
	iter first_;
	iter second_;

	public:
		IteratorRange(iter first, iter second)
		: first_(first), second_(second) {}

		iter begin() {
			return first_;
		}

		iter end() {
			return second_;
		}
};


template <typename iter, typename pred>
class filter {
	IteratorRange<iter> it_;
	iter curr_;
	pred pr_;

	public:
		filter(IteratorRange<iter> it, pred pr)
		: it_(it), pr_(pr) {
			curr_ = it_.begin();
		}

		iter& operator++() {
			iter temp_ = curr_;

			if (curr_ != it_.end()) {
				curr_++;
			}
			
			while (curr_ != it_.end()) {
				if (pr_(*curr_)) {
					return curr_;
				}

				++curr_;
			}

			curr_ = temp_;

			return curr_;
		}
};

template <typename T>
class is_even {
	public:
		bool operator()(T x) {
			if (x % 2 == 0) 
				return true;
			return false;
		}
};

int main() {
	vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    IteratorRange<decltype(v1.begin())> i1(v1.begin(), v1.end());
    cout << *i1.begin() << "\n";

    is_even<int> e1;

    filter<decltype(v1.begin()), is_even<int>> f1(i1, e1);

    cout << *(++f1) << endl;
    cout << *(++f1) << endl;
    cout << *(++f1) << endl;
    cout << *(++f1) << endl;
	cout << *(++f1) << endl;
	cout << *(++f1) << endl;

    return 0;
}