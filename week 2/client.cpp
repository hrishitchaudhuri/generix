#include<iostream>
#include"add.h"

int main() {
	int a(10), b(20), c(30);

	std::cout << add2(a, b) << std::endl;
	std::cout << add3(a, b, c) << std::endl;
	return 0;
}

