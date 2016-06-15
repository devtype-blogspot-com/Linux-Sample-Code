#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
       
int main(int c, char **v) {
	int shmid1 = shmget(atoi(v[1]), 1000, 0);
	int *data1 = shmat(shmid1, (void *)0, SHM_RDONLY);
	
	int shmid2 = shmget(atoi(v[2]), 1000, 0);
	int *data2 = shmat(shmid2, (void *)0, SHM_RDONLY);
	
	key_t key = ftok("solution.c", 'R');
	
	// creates a 1K segment with 644 permissions (rw-r--r--):
	int shmid = shmget(key, 1000, 0644 | IPC_CREAT);
	
	int *data = shmat(shmid, (void *)0, 0);
	
	int i = 0;
	for (i = 0; i < 100; i++) {
		data[i] = data1[i] + data2[i];
	}
	
	printf("%d\n", key);
	
	return 0;
}

