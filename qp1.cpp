#include<iostream>

using namespace std;

#if 0
template <typename T>
void fun(const T& x) {
	static int count = 0;
	cout << "x : " << x << "\ncount : " << count << "\n";

	++count;
	return;
}
#endif

#if 0
template <class T, int max>
int arrMin(T arr[], int n) {
	int m = max;

	for (int i = 0; i < n; i++)
		if (arr[i] < m)
			m = arr[i];

	return m;
}
#endif

#if 1
template <class T>
T mymax(const T& a, const T& b) {
	cout << "one";
	return (a > b) ? a : b;
}

template <>
int mymax<int>(const int& a, const int& b) {
	cout << "two";
	return (a > b) ? a : b;
}

template <>
long mymax<long>(const long& a, const long& b) {
	cout << "three";
	return (a > b) ? a : b;
}

template <>
string mymax(const string& a, const string& b) {
	cout << "four";
	return (a > b) ? a : b;
}
#endif

int main() {
	
	#if 0
	fun<int>(1);
	fun<int>(1);
	fun<double>(1.1);
	#endif

	#if 0
	int a[] = {20, 15, 10, 30};

	cout << arrMin<int, 100>(a, 4) << "\n";
	cout << arrMin<int, 0>(a, 4) << "\n";
	#endif

	#if 1
	int a = 10;
	int b = 20;

	string c = "apple";
	string d = "banana";

	cout << mymax<int>(a, b) << "\n";
	cout << mymax(10l, 20l) << "\n";
	cout << mymax<long>(a, b) << "\n";

	cout << mymax<char>(c[0], d[0]) << "\n";
	cout << mymax(c, d) << "\n";
	cout << mymax(c.c_str(), d.c_str()) << "\n";
	#endif

	return 0;
}
