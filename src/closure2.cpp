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
    // Use lambda to print out each element
    // of vector vec 'and' each character in string 'str'
    /** UNCOMMENT TASK 1
    cout << "============================================================================================" << endl;
    cout << "vec: ";
    for_each(begin(vec), end(vec), lambda );    // TODO: lambda
    cout << endl;
    cout << "str: ";
    for_each(begin(str), end(str), lambda );     // TODO: lambda
    cout << endl << "============================================================================================" << endl;

    CHECK_EQUAL("Task 1a :", vec, VEC_ORIGINAL);
    CHECK_EQUAL("Task 1b :", str, STR_ORIGINAL);
    UNCOMMENT */

    // ############################################################################################


    // ### Task 2 ###
    // Use lambda to convert each lowercase letter in 'str' to uppercase
    /** UNCOMMENT TASK 2
    for_each(begin(str), end(str), lambda );    // TODO: lanmbda

    CHECK_EQUAL("Task 2 :", str, string("ARM HOLDINGS PLC (ARM) IS A BRITISH MULTINATIONAL SEMICONDUCTOR AND SOFTWARE DESIGN COMPANY."));
    UNCOMMENT */

    // ############################################################################################


    // ### Task 3 ###
    // Use lambda to increment / decrement vector 'vec' values
    /** UNCOMMENT TASK 3
    for_each(begin(vec), end(vec), lambda ); // TODO: lambda

    CHECK_EQUAL("Task 3 :", vec, VEC_INC);
    UNCOMMENT */

    // ############################################################################################


    // ### Task 4 ###
    // Use lambda to sum each element in vector 'vec'
    /** UNCOMMENT TASK 4
    int sum = 0;
    for_each(begin(vec), end(vec), lambda );    // TODO: lambda

    CHECK_EQUAL("Task 4 :", sum, 65);
    UNCOMMENT */

    return 0;
}
