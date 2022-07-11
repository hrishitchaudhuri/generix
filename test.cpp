#include<iostream>
#include<vector>

using namespace std;

#if 0
template <typename T>
bool eq(T x, T y) {
	return x == y;
}

int main() {
	cout << boolalpha;

	char a[] = "pes";
	char *b = a;
	char c[] = "pes";

	cout << eq(a, b) << "\n";
	cout << eq(a, c) << "\n";
}
#endif

#if 0
template <typename T>
T what(T x) {
	return x * x;
}

int main() {
	int a[] = {5, 3, 2, 1, 4};

	// cout << what(a) << "\n";
	cout << what(*a) << "\n";

	return 0;
}
#endif

#if 0
template <class T>
T mymax(const T &a, const T &b) {
	cout << "one";
	return (a > b) ? a : b;
}

template <>
int mymax<int>(const int &a, const int &b) {
	cout << "two";
	return (a > b) ? a : b;
}

template <>
long mymax<long>(const long &a, const long &b) {
	cout << "three";
	return (a > b) ? a : b;
}

template <>
string mymax(const string &a, const string &b) {
	cout << "four";
	return (a > b) ? a : b;
}

int main() {
	int a = 10, b = 20;
	string c = "apple";
	string d = "banana";

	cout << mymax<int>(a, b) << "\n";
	cout << mymax(10l, 20l) << "\n";
	cout << mymax<long>(a, b) << "\n";
	cout << mymax<char>(c[0], d[0]) << "\n";
	cout << mymax(c, d) << "\n";
	cout << mymax(c.c_str(), d.c_str()) << "\n";

	return 0;
}
#endif

#if 0
void what(int& x, int& y) {
	int a(x);
	int b(y);

	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}

	x /= a;
	y /= b;
}

int main() {
	int m(25);
	int n(15);

	// what(m, n);

	// cout << m << " " << n << "\n";

	what(m, m);

	cout << m << " " << n << "\n";

	return 0;
}++
#endif

#if 0
int f1(int x) {
	return x;
}

int& f2(int& x) {
	return x;
}

int main() {
	int a(20), b;

	b = f1(a);
	b = 30;
	cout << a << "\n";

	b = f2(a);
	b = 30;

	f2(a) = 40;
	cout << a << "\n";

	return 0;
}
#endif

int main() {
	vector<int> *a;
	return 0;
}
