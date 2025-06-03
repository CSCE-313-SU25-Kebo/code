/*
Example: execl
 */

#include <iostream>
#include <stdexcept>
#include <unistd.h>
using namespace std;

int main()
{
    const char *file = "/home/davidkebo/arithmetic/calculator.sh";
    const char *arg1 = "5";
    execl(file, file, arg1, NULL); // Binary + Path to the Binary + Rest of the options ... + NULL
    cout << "======AFTER========" << endl;
    return 0;
}
