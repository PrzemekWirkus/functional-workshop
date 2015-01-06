/**
    Simplified unit testing macro features used to verify workshop exercises.
*/

#include <functional>
#include <algorithm>
#include <iostream>

#define __NOT !

template<typename T1, typename T2>
bool CHECK_EQUAL(const char *str, T1 t1, T2 t2) {
    using namespace std;

    bool result = true;
    if (__NOT equal(begin(t1), end(t1), begin(t2))) {
        auto mypair = 
            mismatch(begin(t1), end(t1), begin(t2));
        cout << __FILE__ << ": Array mismatch: " << endl;
        for_each(begin(t1), end(t1), [] (typename T1::value_type i) { cout << i << " "; });
        cout << endl;
        for_each(begin(t2), end(t2), [] (typename T1::value_type i) { cout << i << " "; });
        cout << endl;
        result = false;
    }
    cout << str << "\t" << (result ? "OK" : "FAIL") << endl;
    return result;
}

template<>
bool CHECK_EQUAL<int, int>(const char *str, int t1, int t2) {
    using namespace std;

    bool result = t1 == t2;
    if (__NOT result) {
        cout << endl << __FILE__ << ": Value mismatch: " << t1 << " != " << t2 << endl;
    }
    cout << str << "\t" << (result ? "OK" : "FAIL") << endl;
    return result;
}

#undef __NOT
