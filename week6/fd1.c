#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

/*
Independent processes has a File Table contains file descriptors: 0, 1, 2, 3, 4 ... etc.
Parent and child processes share the same file descriptors.
*/

int main()
{
	char c1, c2, c3;
	int fd1 = open("sample.txt", O_RDONLY, O_CREAT, 0); // 3
	int fd2 = open("sample.txt", O_RDONLY, 0);			// 4
	int fd3 = open("sample.txt", O_RDONLY, 0); 			// 5

	printf("%d %d %d\n", fd1, fd2, fd3);
	dup2(fd2, fd3); // Copy of file descriptor

	read(fd1, &c1, 1);
	printf("c = %c\n", c1);

	read(fd2, &c2, 1);
	printf("c = %c\n", c2);

	read(fd3, &c3, 1);
	printf("c = %c\n", c3);
	
	read(fd3, &c3, 1);
	printf("c = %c\n", c3);

	read(fd2, &c2, 1);
	printf("c (fd2) = %c\n", c2);
	
	exit(0);



}
