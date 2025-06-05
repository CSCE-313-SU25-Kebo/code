/*
Example: execlp
 */

#include <iostream>
#include <stdexcept>
#include <unistd.h>
using namespace std;

int main()
{
    const char *file = "calculator.sh";
    const char *arg1 = "12";
    execlp(file, file, arg1, NULL);
    return 0;
}
