#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

int test_shm_read(int shm_fd, void *buf)
{
	read(shm_fd, buf, 0x1000);

	printf("------------------TEST READ------------------\n");
	printf("Content from kernel:\t%x %x\n",
                *(int *)buf, *(int *)(buf + (1 << 8)));
	return 0;
}

int test_shm_write(int shm_fd, void *buf)
{
	printf("------------------TEST WRITE------------------\n");
	read(shm_fd, buf, 0x1000);
	*(int *)buf = 0x1234;
	*(int *)(buf + (1 << 8)) = 0x5678;
	printf("Content to kernel:\t%x %x\n",
                *(int *)buf, *(int *)(buf + (1 << 8)));
	write(shm_fd, buf, 0x1000);
	return 0;
}

int test_shm_mmap(int shm_fd, void *buf)
{
	printf("------------------TEST MMAP------------------\n");
	buf = mmap(NULL, 0x1000, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd, 0);
	printf("Content from kernel:\t%x %x\n",
                *(int *)buf, *(int *)(buf + (1 << 8)));

	*(int *)buf = 0x1111;
	*(int *)(buf + (1 << 8)) = 0x2222;
	printf("Content to kernel:\t%x %x\n",
                *(int *)buf, *(int *)(buf + (1 << 8)));
	return 0;
}

int main()
{
	int shm_fd;
	void *buf;

	shm_fd = open("/dev/shm_kernel_driver", O_RDWR);
	buf = malloc(0x1000);

	test_shm_read(shm_fd, buf);
	test_shm_write(shm_fd, buf);
	test_shm_mmap(shm_fd, buf);
	test_shm_read(shm_fd, buf);

	close(shm_fd);
	return 0;
}

