#include <iostream>

#define CURRENT_MODE Assert::Mode::throw_
#define CURRENT_LEVEL 1
#include "assert.h"

using namespace std;

int main() {
    try {
        Assert::dynamic<true,Assert::Error>(
                true, "Test 1: FAILED!\n");
        cout << "Test 1: OK\n";
    } catch (Assert::Error& err) {
        cout << err.what();
    }
    try {
        Assert::dynamic<true,Assert::Error>(
                false, Assert::compose(__FILE__,__LINE__,"Test 2: OK\n"));
    } catch (Assert::Error& err) {
        cout << err.what();
    }
    try {
        Assert::dynamic(
                false, Assert::compose(__FILE__,__LINE__,"Test 3: OK\n"));
        cout << "Test 3: FAILED!\n";
    } catch (Assert::Error& err) {
        cout << err.what();
    }
    try {
        Assert::dynamic(
                false);
        cout << "Test 4: FAILED!\n";
    } catch (Assert::Error& err) {
        cout << "Test 4: OK " << err.what() << " \n";
    }
    try {
        Assert::dynamic<Assert::level(3),Assert::Error>(
                true, "This should disappear");
    } catch (Assert::Error& err) {
        cout << err.what();
    }

    return 0;
}
