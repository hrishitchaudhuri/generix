#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << boolalpha;

// -------------------------------------------------------------------------------------
mt19937_64 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
T generate(T lower, T upper) {
    return uniform_int_distribution<T>(lower, upper)(rng);
}

template <class T, class U>
U get_it_range(size_t size) {
    U res;
    for (int i = 0; i < (int)size; ++i) {
        res.push_front(generate<T>((T)0, (T)100));
    }
    return res;
}

template <class T>
vector<T> get_vector(size_t size) {
    vector<T> res;
    for (int i = 0; i < (int)size; ++i) {
        res.push_back(generate<T>((T)0, (T)100));
    }
    return res;
}

template <class T>
void print(T& it_range) {
    dbg(it_range);
    for (auto i: it_range) {
        cout << i << " ";
    }
    cout << "\n";
}

template <class T>
void my_sort_lists(T& x) {
    x.sort();
    return;
}

template <class T>
void my_sort_vector(vector<T>& x) {
    sort(x.begin(), x.end());
}

template <class T>
int get_size_forward_list(forward_list<T>& x) {
    return distance(x.begin(), x.end());
}

template <class T>
int get_size(T x) {
    return x.size();
}

// -------------------------------------------------------------------------------------
template <class T, class U, class func_t>
T getXthQuartileRangeForwardBackwardIterator(U& x, int step1, int step2, func_t get_size) {
    auto it = x.begin();
    int size = get_size(x);
    advance(it, (int)((step1*1.0/step2) * size));
    return *it;
}

template <class T, class U, class func_t>
T getXthQuartileRangeRandomIterator(U& x, int step1, int step2, func_t get_size) {
    int size = get_size(x);
    return x[(step1 * 1.0/step2) * size];
}

template <class U, class func1_t, class func2_t, class func3_t>
void FindQuartile(U x, func1_t sorter, func2_t getXthQuartileRange, func3_t get_size, int stepForThirdQuartile = 3) {
    sorter(x);
    dbg(x)
    print(x);

    cout << "First Quartile:\n";
    cout << getXthQuartileRange(x, 1, 4, get_size) << "\n";

    cout << "Second Quartile:\n";
    cout << getXthQuartileRange(x, 1, 2, get_size) << "\n";

    cout << "Third Quartile:\n";
    cout << getXthQuartileRange(x, stepForThirdQuartile, 4, get_size) << "\n";
}
// -------------------------------------------------------------------------------------


int main() {

    auto f_list = get_it_range<int, forward_list<int>>(12);

    cout << "Forward List:\n";
    FindQuartile<forward_list<int>,
                decltype(my_sort_lists<forward_list<int>>),
                decltype(getXthQuartileRangeForwardBackwardIterator<int, forward_list<int>, decltype(get_size_forward_list<int>)>),
                decltype(get_size_forward_list<int>)>
                (f_list, my_sort_lists, getXthQuartileRangeForwardBackwardIterator, get_size_forward_list);
    cout << "\n------------------------\n";

    auto bi_list = get_it_range<int, list<int>>(12);
    cout << "List:\n";
    FindQuartile<list<int>,
                 decltype(my_sort_lists<list<int>>),
                 decltype(getXthQuartileRangeForwardBackwardIterator<int, list<int>, decltype(get_size<list<int>>)>),
                 decltype(get_size<list<int>>)>
                 (bi_list, my_sort_lists, getXthQuartileRangeForwardBackwardIterator, get_size, -1);
    cout << "\n------------------------\n";

    auto vec = get_vector<int>(12);
    cout << "Vector:\n";
    FindQuartile<vector<int>,
                 decltype(my_sort_vector<int>),
                 decltype(getXthQuartileRangeRandomIterator<int, vector<int>, decltype(get_size<vector<int>>)>),
                 decltype(get_size<vector<int>>)>
                 (vec, my_sort_vector, getXthQuartileRangeRandomIterator, get_size);
    cout << "\n------------------------\n";

    cout << "How do you find the middle element of a linked list?\nHave a fast pointer and a slow pointer, for every two jumps of the fast pointer, the slow pointer jumps by one. So this ensures that when the fast pointer reaches the end of the list, the slow pointer will be at the middle element.";

    return 0;
}
