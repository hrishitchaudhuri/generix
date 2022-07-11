#include<cstdarg>
int sum(int n, ...) {
	va_list va;
	va_start(va, n);

	int s = 0;

	while (n--) {
		s += va_arg(va, int); // define expected type as a parameter
		// get value from stack of specified type; advance va to next location.
	}

	va_end(va);
	return s;
}

// va_args(va, int) MUST be a macro since functions cannot take a typename as an argument
