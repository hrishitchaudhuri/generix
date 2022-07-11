#include<iostream>
#include<type_traits>

#if 0
template <typename T, typename Val>
Val Accumulate(T first, T last) {
	// declval returns an rvalue reference
	// (creates an object of type T)

	Val accumulator{};
	while (first != last) {
		accumulator += (*first);
		++first;
	}

	return accumulator;
}
#endif

// ideally, do not want to pass an extra parameter "Val".
// instead, use TRAIT classes.

template <typename T>
struct ReturnType{
	// if sequence is of type int	: -> long
	//			  char 	: -> int
	//			  float	: -> double

	// idea: specialize over the types.
};

template<>
struct ReturnType<int *> {
	using RT = long;
	static constexpr RT val = 100;

	// change initial value for accumulate.
};

template<>
struct ReturnType<char *> {
	using RT = int;
	static constexpr RT val = 200;
};

template<>
struct ReturnType<float *> {
	using RT = double;
	static constexpr RT val = 300.0f;
};

#if 0
template <typename T>
typename ReturnType<T>::RT Accumulate(T first, T last) {
	typename ReturnType<T>::RT accumulator = ReturnType<T>::val;

	std::cout << typeid(typename ReturnType<T>::RT).name() << "\n";

	while (first != last) {
		accumulator += (*first);
		++first;
	}

	return accumulator;
}
#endif

template <typename T, typename _RT = typename ReturnType<T>::RT>
_RT Accumulate(T first, T last) {
	_RT accumulator = ReturnType<T>::val;

	std::cout << typeid(_RT).name() << "\n";

	while (first != last) {
		accumulator += (*first);
		++first;
	}

	return accumulator;
}

#if 0
template <typename T, typename Callable, typename _RT = typename ReturnType<T>::RT>
_RT Accumulate(T first, T last, Callable C) {
	_RT accumulator = 1;

	std::cout << typeid(_RT).name() << "\n";

	while (first != last) {
		accumulator = C(*first, accumulator);
		++first;
	}

	return accumulator;
}
#endif

template <typename T>
struct AddOp {
	static constexpr ReturnType<T>::RT init = 0;
}

template <typename T, typename AccumPolicy = , typename _RT = typename ReturnType<T>::RT>
_RT Accumulate(T first, T last) {
	// the accumulation policy defines both the identity (initial)
	// and the operation to be performed

	_RT accumulator = AccumPolicy::init;

	std::cout << typeid(_RT).name() << "\n";

	while (first != last) {
		accumulator = AccumPolicy::op(*first, accumulator);
		++first;
	}

	return accumulator;
}

int main() {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	char b[] = {'h', 'e', 'l', 'l', 'o'};
	float c[] = {1.2f, 3.4f, 5.6f, 7.8f, 9.0f};

	// std::cout << Accumulate<int *, int>(a, a + sizeof(a) / sizeof(int)) << "\n";
	// std::cout << Accumulate<int *, char>(a, a + sizeof(a) / sizeof(int)) << "\n";
	// std::cout << Accumulate<int *, float>(a, a + sizeof(a) / sizeof(int)) << "\n";

	std::cout << Accumulate(a, a + sizeof(a) / sizeof(int)) << "\n";
	std::cout << Accumulate(b, b + sizeof(b)) << "\n";
	std::cout << Accumulate(c, c + sizeof(c) / sizeof(float)) << "\n";

	std::cout << std::is_same<double, decltype(Accumulate(c, c + 5))>::value 
		<< "\n";
		// this does not execute Accumulate; decltype gets the type
		// of the expression @ compiler-time without invoking it.

	std::cout << Accumulate(a, a + sizeof(a) / sizeof(int),
		[](long x, long y) -> long { return x * y; }) << "\n";

	return 0;
}
