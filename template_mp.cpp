#include<iostream>

template <size_t I>
struct factorial {
	static constexpr size_t value = I * factorial<I - 1>::value;
};

// constexpr: used to indicate an expr must be eval @ compile time

template <>
struct factorial<0> {
	static constexpr size_t value = 1;
};

/************/

// Type creation with template metaprogramming.

template <typename T, T Value>
struct integral_constant {
	static constexpr T value = Value;
};

struct true_type
	: integral_constant<bool, true> {};

struct false_type
	: integral_constant<bool, false> {};

// Type-checking: hack by partial specialization.
template <typename T, typename V>
struct is_same
	: false_type {};

template <typename T>
struct is_same<T, T>
	: true_type {};

// Selection using partial specialization.
template <bool Value, typename T, typename V>
struct conditional {
	using type = V;
		// using -> a cooler way to typedef
};

template <typename T, typename V>
struct conditional<true, T, V> {
	using type = T;
};

// If-Else.

template <bool Value, typename T>
struct enable_if;

template <typename T>
struct enable_if<true, T> {
	using type = T;
};

// Square Root Calculation.

#if 0
template <uint32_t I, uint32_t Value>
struct SqrtImpl {
	static constexpr uint32_t value = ((I * I) < Value) ? SqrtImpl<I + 1, Value>::value : I;
};
#endif

template <uint32_t I, uint32_t Value>
struct SqrtImpl {
	static constexpr uint32_t value = conditional<(I * I < Value), SqrtImpl<I + 1, Value>, integral_constant<uint32_t, I>>::type::value;
};

template <uint32_t I>
struct SqrtImpl<I, I>{
	static constexpr uint32_t value = I;
};

template <uint32_t Value>
struct Sqrt {
	// if you are given (i, N) : return i iff i * i == N
	// N => {1 ... N} : square each element and check equality

	// Binary Search -> find midpoint.

	static constexpr uint32_t value = SqrtImpl<1, Value>::value;
};

/**************************/

template <uint32_t>

template <uint32_t Value>
struct sqrt : sqrt_impl<Value, 1, Value> {};

#if 0
int isqrt(int value, int start, int last) {
	int mid = (start + last) / 2;

	if (start == last) {
		return mid;
	}

	if (mid * mid <= value) {
		return isqrt(value, mid, last);
	}

	return isqrt(value, start, mid);
}
#endif

int main() {
	std::cout << factorial<5>::value << "\n";
		// factorial<5> forces a specialization of factorial<4>
		// which then forces factorial<3> and so on.

	std::cout << integral_constant<int, 5>::value << "\n";
	std::cout << true_type::value << "\n";
		// Out: 1

	std::cout << is_same<int, float>::value << "\n";
	std::cout << is_same<uint, uint32_t>::value << "\n";
		// SFINAE: Substitution Failure Is Not An Error

	std::cout << is_same<typename conditional<sizeof(int) == 4, float, double>::type, float>::value << "\n";

	std::cout << is_same<typename enable_if<sizeof(int) == 4, float>::type, float>::value << std::endl;
	// std::cout << is_same<typename enable_if<sizeof(int) == sizeof(char), bool>::type, bool>::value << "\n";

	std::cout << (Sqrt<99>::value) << "\n";

	return 0;
}

/*
 * NOTE: Template Meta-Programming is Turing-complete
 * 		i.e. -> it can do SELECTION and LOOPING via partial specs
 */
