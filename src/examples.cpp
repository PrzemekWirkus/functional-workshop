/**
    Functional programming simple examples.
 */

#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include "utest.h"

using namespace std;


// Bubble sort
template<class T, class CompareType>
void bubble_sort(T* _array, int Count, const CompareType& Compare) {
	for(int i = 0; i < Count; ++i) {
		for(int j = i + 1; j < Count; ++j) {
            // functor call
            if (Compare(_array[i], _array[j])) {
                // exchange of two elements
                const T temp = _array[i];
                _array[i] = _array[j];
                _array[j] = temp;
            }
        }
	}
}

// Functor, predicate used to compare only absolute values
// Note: you can negate absoluteLess using std::not2 only if
// the class inherits from std::binary_function
struct absoluteLess : public std::binary_function<int, int , bool> {
	bool operator()(int x, int y) const { return abs(x) < abs(y); }
};

#define TABLE_PRINT()       for_each(Table, Table + TableSize, [] (int i) { cout << i << " "; }); cout << endl;
#define VECTOR_PRINT()      for_each(vec.begin(), vec.end(), [] (int i) { cout << i << " "; }); cout << endl;
#define F_PRINT()           cout << *f << endl;


int main(int argc, char *argv[]) {
    // ######### Example 1 - sorting with binary predicate #########
    {
        cout << "Example 1:" << endl;

        int Table[] = {55, -7, 3, -9, 2, -9198, -937, 1, 473};
        const int TableSize = sizeof(Table) / sizeof(int);

        // Print C-style table:
        // for_each(Table, Table + TableSize, [] (int i) { cout << i << " "; }); cout << endl;
        TABLE_PRINT();

        // ### Variation 1.1, std::less predicate
        std::less<int> normalCompare;
        bool b = normalCompare(4, 6); // 4 < 6
        bubble_sort(Table, TableSize, normalCompare);     // Sort big -> small
        TABLE_PRINT();
        // or
        bubble_sort(Table, TableSize, std::less<int>());  // Like above
        TABLE_PRINT();

        // ### Variation 1.2, reverse sorting order
        bubble_sort(Table, TableSize, std::greater<int>()); // Sort small -> big, reverse order
        TABLE_PRINT();
        // or
        bubble_sort(Table, TableSize, std::not2(std::less<int>())); // Sort small -> big, reverse order
        TABLE_PRINT();

        // ### variation 1.3, sort as if values in array are absolute
        bubble_sort(Table, TableSize, absoluteLess());
        TABLE_PRINT();
        // or in reverse order
        bubble_sort(Table, TableSize, std::not2(absoluteLess()));
        TABLE_PRINT();
    }

    // ######### Example 2 #########
    {
        cout << "Example 2:" << endl;

        vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        VECTOR_PRINT();

        // ### variation 2.1
        // finds the first number in the int vector v which is less than 3
        vector<int>::reverse_iterator f = vec.rend();
        f = find_if(vec.rbegin(), vec.rend(), bind2nd(less<int>(), 3)); // bind 2nd!
        F_PRINT();

        // ### variation 2.2
        // finds the first number in the int vector v which is not less than 5
        f = std::find_if(vec.rbegin(), vec.rend(), std::bind1st(std::less<int>(), 5)); // bind 1nd!
        F_PRINT();

        // ### variation 2.3
        // finds the first number in the int vector v which is greater than 7
        f = std::find_if(vec.rbegin(), vec.rend(), std::bind2nd(std::greater<int>(), 7)); // bind 2nd!
        F_PRINT();

        // ### variation 2.4
        // finds the first number in the int vector v which is equal to 4
        f = std::find_if(vec.rbegin(), vec.rend(), std::bind1st(std::equal_to<int>(), 4)); // bind 1nd!
        F_PRINT();
    }

    // ######### Example 3 #########
    {
        // ### variation 3.1

    	vector<string> Gals = {
            string("Annabella"),
            string("Scheherazade"),
            string("Xaviera")};
        vector<string> Guys = {
            string("Bogey"),
            string("Amadeus"),
            string("Wladimir")};
        vector<string> Couples(3);

        // ### variation 3.2 transform with unary predicate
        // target == source
        std::transform(Guys.begin(),
                       Guys.end(),
                       Guys.begin(),
                        [] (string &s) {
                            for_each(begin(s), end(s),
                                [] (string::value_type &c) {
                                    if (c >= 'a' && c <= 'z') {
                                        c -= 'a' - 'A';
                                    }
                                }
                            );
                            return s;
                        });

        // Print
        for_each(Guys.begin(), Guys.end(), [] (const string &s) { cout << s << " "; }); cout << endl;

        // ### variation 3.3, transform and grab in lambda global variable as reference
        string connector = " and ";

        std::transform(Gals.begin(),
                       Gals.end(),
                       Guys.begin(),
                       Couples.begin(),
                       [&connector] (const std::string& a, const std::string& b) {
                            return a + connector + b;
                       });

        // Print
        for_each(Couples.begin(), Couples.end(), [] (const string &s) { cout << s << endl; });

    }

    return 0;
}
