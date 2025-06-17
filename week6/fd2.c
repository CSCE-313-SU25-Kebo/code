/*
Parent fork child process
Child process inherit the file descriptor of the parent.
file position can be updated from both processes
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
Independent processes has a File Table contains file descriptors: 0, 1, 2, 3, 4 ... etc.
Parent and child processes share the same file descriptors.
*/

int main()
{
	char c;
	char parent_char;
	int fd = open("sample.txt", O_RDONLY, 0); // File descriptor SHARED between the child and parent process
	if (fork() == 0)
	{
		printf("File descriptor (Child side): %d \n", fd);
		read(fd, &c, 1); // In the child read one character from Minecraft - character 'M'
		printf("Child --- c = %c\n", c);

		read(fd, &c, 1); // In the child read one character from Minecraft - character 'i'
		printf("Child --- c = %c\n", c);

		read(fd, &c, 1); // In the child read one character from Minecraft - character 'n'
		printf("Child --- c = %c\n", c);

		read(fd, &c, 1); // In the child read one character from Minecraft - character 'e'
		printf("Child --- c = %c\n", c);
		//return 0;
	}

	// Both the parent and child process run the section below

	//wait(0); // Wait for the child to finish updating the fd
	int fd2 = open("sample.txt", O_RDONLY, 0); // Created after the fork syscall
	printf("File descriptor (Parent side): %d \n", fd);
	lseek(fd, -1, SEEK_CUR);
	read(fd, &c, 1); // In the parent read one character from Minecraft - character ??


	read(fd2, &parent_char, 1);
	printf("Parent --- c = %c\n", c);
	printf("Parent read char from --- c = %c\n", parent_char);

	exit(0);
}

/*
- parent
-- child 1
*/

/*
The child copies the file descriptor
--------- M
--------- i
--------- n
--------- e << child finishes HERE
--------- c
--------- r
--------- a
---------
---------



*/