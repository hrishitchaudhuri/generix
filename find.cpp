#include<iostream>
#include<vector>

/*
 *
 */

template <typename T>
struct multiply {
	T operator()(T first, T second) {
		return first * second;
	}
};

template <typename Iterator, typename T, typename Operation>
T accumulate(Iterator first, Iterator last, T init, Operation op) {
	// last -> point to logical end (usually one past the end)

	T acc = init;

	while (first != last) {
		acc = op(acc, *first);
		++first;
	}

	return acc;
}

int main() {
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::vector<int> Vector{1, 2, 3, 4, 5, 6, 7, 8, 9}; 
		// uniform initialization

	multiply<int> m;

	// std::cout << accumulate(array, array + 10, 1, m) << "\n";
	// std::cout << accumulate(Vector.begin(), Vector.end(), 1, m) << "\n";
	
	std::cout << accumulate(std::begin(array), std::end(array), 1, m) << "\n";
	std::cout << accumulate(std::begin(Vector), std::end(Vector), 1, m) << "\n";
	return 0;
}
