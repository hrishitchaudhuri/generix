#include<iostream>
#include<vector>

using namespace std;

int median(int left, int right) {
	return ((right - left + 2) / 2 - 1) + left;
}

template <typename iter>
int getSize(iter first, iter last) {
	int size = 0;

	while (first != last) {
		size++;
		++first;
	}

	return size;
}

template <typename iter>
void findQuartiles(iter first, iter last) {
	int size = getSize(first, last);

	int q2 = median(0, size);
	int q1 = median(0, q2);
	int q3 = median(q2 + 1, size);

	cout << "FIRST QUARTILE: ";
	for (int i = 0; i < q1; i++) {
		cout << *first << " ";
		++first;
	}

	cout << "\n";

	cout << "SECOND QUARTILE: ";
	for (int i = q1; i < q2; i++) {
		cout << *first << " ";
		++first;
	}

	cout << "\n";	

	cout << "THIRD QUARTILE: ";
	for (int i = q2; i < q3; i++) {
		cout << *first << " ";
		++first;
	}

	cout << "\n";

	cout << "FOURTH QUARTILE: ";
	for (int i = 0; i < q1; i++) {
		cout << *first << " ";
		++first;
	}

	cout << "\n";
}

template <typename iter>
void findQuartilesTwoPointer(iter first, iter last) {
	iter q1 = first, q2 = first, q3 = first, q4 = first;

	while (q4 != last) {
		++q1;
		++q2;
		++q3;
		++q4;

		if (q4 != last) {
			++q2;
			++q3;
			++q4;
		}

		if (q4 != last) {
			++q3;
			++q4;
		}

		if (q4 != last) {
			++q4;
		}
	}

	iter temp = first;

	cout << "FIRST QUARTILE: ";

	while (temp != q1) {
		cout << *temp << " ";
		++temp;
	}

	cout << "\n";

	cout << "SECOND QUARTILE: ";

	while (temp != q2) {
		cout << *temp << " ";
		++temp;
	}

	cout << "\n";

	cout << "THIRD QUARTILE: ";

	while (temp != q3) {
		cout << *temp << " ";
		++temp;
	}

	cout << "\n";

	cout << "FOURTH QUARTILE: ";

	while (temp != q4) {
		cout << *temp << " ";
		++temp;
	}

	cout << "\n";
}

int main() {
	std::vector<int> v1;

    for (int i = 16; i < 101; i += 4) {
        v1.push_back(i);
    }

    findQuartiles(v1.begin(), v1.end());
    findQuartilesTwoPointer(v1.begin(), v1.end());
}
