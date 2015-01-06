/**
    Name: BIND (bind function and placeholders introduction)
    Exercise: Prepare mutable and non-mutable functors and use them with algorithm

    Description:
    This exercise is an introductory exercise with Lambda function in C++11.
    BOOST library offers similar functionality in boost::lambda module.

 */

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>
#include "utest.h"
#include <memory>

using namespace std;
using namespace std::placeholders;  // _1, _2, _3, _4 ...

namespace {
    string SPACE_STRING = "                                                                                            ";
}

int main(int argc, char *argv[]) {

    // ### Task 1 ###
    // Create 'printf_complex' function which will print pair of integers as in was complex number.
    //
    //      int printf_complex(const char* format, int, int);
    //
    // Note: you can use std::printf function as stub to create your own printf version
    //
    //      int printf( const char* format, ... );
    //
    // Note: you can use auto feature to declare function type
    //
    // Example:
    //
    //      print_complex(-3, 3);   // prints: (-3, 3)
    //      print_complex(0, 0);    // prints: (0, 0)

    cout << "Task 1..." << endl;
    //std::function<int(int, int)> printf_complex = bind(printf, "(%d, %d)", _1, _2);
    /** UNCOMMENT TASK 1
    auto printf_complex = // TODO: bind(... ;
    printf_complex(-3, 3);
    printf_complex(0, 0);
    cout << endl;
    UNCOMMENT */


    // ############################################################################################


    // ### Task 2 ###
    // Create memset's specialization called 'strsetspace' which will replace all characters
    // in string with space character ' '.
    // Example:  "hello world!" -> strsetspace -> "            "
    //
    // Note: In your code developers were using this below simple code to do this task.
    //
    //      memset(str, ' ', strlen(str));  // void * memset ( void * ptr, int value, size_t num );
    //
    // we can replace with below equivalent:
    //
    // strsetspace(str);

    cout << "Task 2..." << endl;
    char str[] = "ARM Holdings plc (ARM) is a British multinational semiconductor and software design company.";
    cout << '[' << str << ']' << endl;

    /** UNCOMMENT TASK 2
    auto strsetspace = // TODO: bind(...
    strsetspace(str);   // Execute new function

    cout << '[' << str << ']' << endl;
    UNCOMMENT */

    CHECK_EQUAL("Task 2 : ",
        string(str),
        string("                                                                                            "));

    return 0;
}
