#include<iostream>

// void foo(int);
void foo(char);
// void foo(double);

using namespace std;

int main() {
	foo(10);
	return 0;
}

void foo(int x) {
	cout << "int" << endl;
}

void foo(char x) {
	cout << "char" << endl;
}

void foo(double x) {
	cout << "double" << endl;
}
