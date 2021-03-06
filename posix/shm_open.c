/*************************************************************************
	> File Name: basic.c
	> Author: Simba
	> Mail: dameng34@163.com 
	> Created Time: Tue 12 Mar 2013 06:54:20 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/mman.h>

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

int main(void)
{
	int  shmid;
	shmid = shm_open("/xyz", O_CREAT | O_RDWR, 0666);
	if (shmid == -1)
		ERR_EXIT("shm_open");
	if (ftruncate(shmid, 36) == -1)
		ERR_EXIT("ftruncate");

	struct stat buf;
	if (fstat(shmid, &buf) == -1)
		ERR_EXIT("fstat");

	printf("size=%ld, mode=%o\n", buf.st_size, buf.st_mode & 0777);
	close(shmid);
	return 0;
}


