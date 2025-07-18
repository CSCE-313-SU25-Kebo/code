/*
Example: fork() and pipe() - *Bug
This program creates a parent process and child process
The goal is for the parent to sent a message to the child process
// Pipe are unidirectional
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	int pipefds[2]; // file descriptor array for the pipe
	pid_t pid;
	char buf[30];
	
	if(pipe(pipefds)==-1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	memset(buf,0,30);
	pid = fork(); // Create 1 child process

	// TODO: send the string CSCE313-24 from the parent to the child
	if(pid>0){
		printf("PARENT: writing to the pipe\n");
		//parent close the read end
		close(pipefds[0]);
		//parent write in the pipe write end
		write(pipefds[1],"CSCE313-24",10);
		//after finishing writing, parent close the write end
		close(pipefds[1]);
		//parent wait for child - parent waits for the return value of the child
		wait(NULL);
	}else{
		//child did not close the write end ?
		// Should we close the write end of the pipe for the child 
		//child read from the pipe's read end until the pipe is empty
		while(read(pipefds[0],buf,1)==1){
			printf("CHILD read from pipe --%s\n",buf);
		}
		// Close the read end of the pipe
		close(pipefds[0]);
		printf("CHILD: EXITING!");
		exit(EXIT_SUCCESS);

	}
	return 0;
}
