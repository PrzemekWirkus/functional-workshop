/**
    Name: CLOSURE_1 (Lambda introduction)
    Exercise: Prepare mutable and non-mutable functors and use them with algorithm

    Description:
    This exercise is an introductory exercise with Lambda function in C++11.
    BOOST library offers similar functionality in boost::lambda module.

 */

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include "utest.h"

using namespace std;


int main(int argc, char *argv[]) {

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string str = "ARM Holdings plc (ARM) is a British multinational semiconductor and software design company.";

    // ### Task 1 ###
    // Use lambda to print out each element
    // of vector vec 'and' each character in string 'str'
    for_each(begin(vec), end(vec), [] (vector<int>::value_type i) { cout << i << " "; });
    for_each(begin(vec), end(vec), cout << std::placeholders::_1 << " ");
    cout << endl;
    for_each(begin(str), end(str), [] (string::value_type i) { cout << i << " "; });
    cout << endl;

    // ### Task 2 ###
    // Use lambda to convert each lowercase letter in 'str' to uppercase
    for_each(begin(str), end(str), [] (string::value_type &i) { if (islower(i)) i += 'A' - 'a'; });
    cout << str;

    // ### Task 3 ###
    // Use lambda to increment / decrement vector 'vec' values
    for_each(begin(vec), end(vec), [] (int &i) { i++; });

    // ### Task 4 ###
    // Use lambda to sum each element in vector 'vec'
    //func_sum<vector<int>::value_type> fs = for_each(begin(vec), end(vec), func_sum<vector<int>::value_type>());
    //cout << endl << fs.count << endl;

    //
    
    
    return 0;
}
