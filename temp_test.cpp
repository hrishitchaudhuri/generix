#include<iostream>
#include<type_traits>

template <typename T, typename K>
void sq(T a, K b) {
	std::cout << typeid(T).name() << " " << a << "\n";
	std::cout << typeid(K).name() << " " << b << "\n";
}

template <>
void sq<int, double>(int a, double b) {
	std::cout << "inside specialization" << "\n";
}

int main() {
	sq(10, 0.03);
	return 0;
}
