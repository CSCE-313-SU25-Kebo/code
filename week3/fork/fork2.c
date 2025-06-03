/*
Example: C program to differentiate a parent process from a child process after a fork
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

void forkexample()
{
	int child_status;
	pid_t pid = fork();
	// child process because the return value is zero
	if (pid == 0)
	{  // Server
		printf("1. Hello from Child!\n");
		printf("1. Child process ID is %d\n", getpid()); // getpid() returns the current process PID
		printf("1. Child: My parent process ID is %d\n", getppid()); // getppid() return sthe process ID of the parent process
	}

	// parent process because the return value is non-zero.
	else
	{   // Client
		//wait(NULL);
		waitpid(pid,&child_status, NULL);
		wait(&child_status); // Waits at least one child process to return an exit status -- Listens to a signal (SIG_CHLD)
		printf("2. Hello from Parent!\n");
		printf("2. Parent process ID is %d\n", getpid());
		printf("2. Parent: My parent process ID is %d\n", getppid());

		// Wait capture the retirn status of the child process from memory
		// store the state in it local variable
	}
}
int main()
{
	forkexample();
	return 0;
}
