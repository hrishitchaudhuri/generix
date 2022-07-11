#include <iostream>
using namespace std;

template <class T, T Value>
struct my_integral_constant {
    static constexpr T value = Value;
};

template <bool Value, class T, class F>
struct my_conditional {
    using type = F;
};

template <class T, class F>
struct my_conditional<true, T, F> {
    using type = T;
};

template <int Begin, int End, int Value>
struct SqrtImpl {
    static constexpr int mid = (Begin + End) >> 1;
    
    static constexpr int value = my_conditional <
                ((mid * mid) < Value),
                SqrtImpl<mid + 1, End, Value>,
                SqrtImpl<Begin, mid, Value>
                >::type::value;
};

template <int Mid, int Value>
struct SqrtImpl<Mid, Mid, Value> {
    static constexpr int value = 
                my_conditional <
                        ((Mid * Mid) == Value),
                        my_integral_constant<int, Mid>,
                        my_integral_constant<int, -1>
                        >::type::value;
};

template <int Value>
struct Sqrt : SqrtImpl<1, Value, Value> {};


int main() {
    cout << Sqrt<100>::value << "\n";
    return 0;
}

