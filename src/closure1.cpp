/**
    Name: CLOSURE_1 (Functor introduction)
    Exercise: Prepare mutable and non-mutable functors and use them with algorithm

    Description:
    This exercise is an introductory exercise with functors which will let you
    understand better mutable and non-mutable functors and lambda functions.

    Note:
    So how does the magic of variable capture really work? It turns out that the
    way lambdas are implemented is by creating a small class; this class overloads
    the operator(), so that it acts just like a function. A lambda function is an
    instance of this class; when the class is constructed, any variables in the
    surrounding environment are passed into the constructor of the lambda function
    class and saved as member variables. This is, in fact, quite a bit like the
    idea of a functor that is already possible. The benefit of C++11 is that doing
    this becomes almost trivially easy--so you can use it all the time, rather than
    only in very rare circumstances where writing a whole new class makes sense.

 */

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include "utest.h"

using namespace std;

// Simplistic functor stencil
struct func {
    void operator()() {
        // TODO:
    }
};

template<typename T> struct func_print {
    void operator()(const T t) {
        cout << t << " ";
    }
};

template<> struct func_print<char> {
    void operator()(char t) {
        cout << t;
    }
};

template <typename T>
struct func_upper {
    func_upper(const int _delta) : delta(_delta) {  }
    int delta;
    void operator()(T &t) {
        if (t >= 'a' && t <= 'z') {
            t += delta;
        }
    }
};

template <>
struct func_upper<int> {
    func_upper(const int _delta) : delta(_delta) {  }
    int delta;
    void operator()(int &t) {
        t += delta;
    }
};


template <typename T>
struct func_sum {
    func_sum() : count(0) {}
    void operator()(T t) {
        count += t;
    }
    T count;
};

namespace {
    // Used to compare results
    vector<int> VEC_ORIGINAL = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> VEC_INC      = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    string STR_ORIGINAL      = "ARM Holdings plc (ARM) is a British multinational semiconductor and software design company.";
}

int main(int argc, char *argv[]) {

    // Variables used for operations in tasks
    vector<int> vec(VEC_ORIGINAL);  // = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string str(STR_ORIGINAL);   //"ARM Holdings plc (ARM) is a British multinational semiconductor and software design company.";

    // ### Task 1 ###
    // Create functor func_print which will be able to print out each element
    // of vector vec 'and' each character in string 'str'
    cout << "============================================================================================" << endl;
    cout << "vec: ";
    for_each(begin(vec), end(vec), func_print<vector<int>::value_type>());
    cout << endl;
    cout << "str: ";
    for_each(begin(str), end(str), func_print<string::value_type>());
    cout << endl << "============================================================================================" << endl;

    CHECK_EQUAL("Task 1a :", vec, VEC_ORIGINAL);
    CHECK_EQUAL("Task 1b :", str, STR_ORIGINAL);

    // ### Task 2 ###
    // Create functor func_upper which will convert each lowercase letter in 'str' to uppercase
    for_each(begin(str), end(str), func_upper<string::value_type>('A' - 'a'));

    CHECK_EQUAL("Task 2 :", str, string("ARM HOLDINGS PLC (ARM) IS A BRITISH MULTINATIONAL SEMICONDUCTOR AND SOFTWARE DESIGN COMPANY."));

    // ### Task 3 ###
    // Modify functor from Task 2 so it can be used to increment / decrement vector 'vec' values
    for_each(begin(vec), end(vec), func_upper<vector<int>::value_type>(1));

    CHECK_EQUAL("Task 3 :", vec, VEC_INC);

    // ### Task 4 ###
    // Create functor func_sum which will sum each element in vector 'vec'
    func_sum<vector<int>::value_type> fs = for_each(begin(vec), end(vec), func_sum<vector<int>::value_type>());

    CHECK_EQUAL("Task 4 :", fs.count, 65);

    // Print your result
    // for_each(begin(vec), end(vec), [] (int i) { cout << i << " "; });   // Print vector
    return 0;
}
