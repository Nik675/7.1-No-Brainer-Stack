#include <iostream>
#include "Person.h"

using namespace std;

int main() {
    Person bt("Bart", 10);
    Person hm("Homer", 42);
    Person mg("Marge", 42);

    // Comparing using >
    if (hm > bt) {
        cout << "Older: " << hm << endl;
        cout << "Younger: " << bt << endl;
    }

    // Comparing using ==
    if(hm == mg) {
        cout << "Same Age: " << endl;
        cout << hm << endl;
        cout << mg << endl;
    }

    // Testing other comparison operators between Person objects
    if (bt < hm) {
        cout << bt << " is younger than " << hm << endl;
    }

    if (hm >= mg) {
        cout << hm << " is at least as old as " << mg << endl;
    }

    if (bt <= hm) {
        cout << bt << " is at most as old as " << hm << endl;
    }

    if (bt != hm) {
        cout << bt << " is not the same age as " << hm << endl;
    }

    // Testing Person comparison with int
    if (bt < 21) {
        cout << bt << " too young for Moes" << endl;
    }

    if (bt > 5) {
        cout << bt << " is older than 5" << endl;
    }

    if (hm >= 40) {
        cout << hm << " is at least 40" << endl;
    }

    if (bt <= 15) {
        cout << bt << " is at most 15" << endl;
    }

    if (hm == 42) {
        cout << hm << " is exactly 42" << endl;
    }

    if (bt != 20) {
        cout << bt << " is not 20" << endl;
    }

    // Testing int comparison with Person (using friend functions)
    if (21 > bt) {
        cout << bt << " less than 21" << endl;
    }

    if (5 < bt) {
        cout << "5 is less than " << bt << endl;
    }

    if (40 <= hm) {
        cout << "40 is less than or equal to " << hm << endl;
    }

    if (15 >= bt) {
        cout << "15 is greater than or equal to " << bt << endl;
    }

    if (42 == hm) {
        cout << "42 equals " << hm << endl;
    }

    if (20 != bt) {
        cout << "20 is not equal to " << bt << endl;
    }

    return 0;
} 