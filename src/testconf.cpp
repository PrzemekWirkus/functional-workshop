/**
    If you can compile this file you are ready to proceed with workshop
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "utest.h"

using namespace std;

// JUast a c++11 example from http://www.cprogramming.com/c++11/c++11-lambda-closures.html
class AddressBook
{
    public:
    // using a template allows us to ignore the differences between functors, function pointers
    // and lambda
    template<typename Func>
    vector<string> findMatchingAddresses (Func func)
    {
        vector<string> results;
        for ( auto itr = _addresses.begin(), end = _addresses.end(); itr != end; ++itr )
        {
            // call the function passed into findMatchingAddresses and see if it matches
            if ( func( *itr ) )
            {
                results.push_back( *itr );
            }
        }
        return results;
    }

    void push_back(string &&s) {
        _addresses.push_back(s);
    }

    private:
    vector<string> _addresses;
};

AddressBook global_address_book;

vector<string> findAddressesFromOrgs () {
    return global_address_book.findMatchingAddresses(
        // we're declaring a lambda here; the [] signals the start
        [] (const string& addr) { return addr.find(".org") != string::npos; }
    );
}


int main()
{
    // auto and lambda
    auto func = [] (string str) {cout << str << endl; };
    func("Lambda function call!"); // now call the function

    // some more templates
    global_address_book.push_back(string("http://www.cprogramming.com"));
    global_address_book.push_back(string("http://mbed.org"));
    global_address_book.push_back(string("http://google.com"));

    vector<string> v = findAddressesFromOrgs();

    cout << endl;
    cout << "Found .org domains:" << endl;
    for_each(v.begin(), v.end(), func);
}
