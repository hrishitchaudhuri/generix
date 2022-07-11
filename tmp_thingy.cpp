#include <iostream>
using namespace std;



template <typename T, T Value>
struct my_integral_constant {
  static constexpr T value = Value;
};

struct my_true_type 
  : my_integral_constant<bool, true> {};

struct my_false_type 
  : my_integral_constant<bool, false> {};

template <typename T, typename V>
struct my_is_same : public my_false_type {} ;

template <typename T>
struct my_is_same<T, T> : public my_true_type {};





template <bool V, class T>
struct my_enable;

template <class T>
struct my_enable<true, T> {
    using type = T;
};

template <class T, typename U = typename my_enable<my_is_same<T, int>::value, T>::type>
void test(T x) {
    cout << "Works with int\n";
}

/*
template <class T, typename U = typename my_enable<!my_is_same<T, int>::value, T>::type>
void test(T x) {
    cout << "Works with other types\n";
}
*/

int main() {
    int x = 1;
    test(x);
    
    float y = 0.3;
    test(y);
    return 0;
}
