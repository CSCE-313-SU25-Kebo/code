/*
Example: execvp
 */

#include <iostream>
#include <stdexcept>
#include <unistd.h>
using namespace std;

int main()
{
    const char *file = "factorial.sh";
    char *const args[] = {"factorial.sh", NULL};
    execvp(file, args);
    return 0;
}
