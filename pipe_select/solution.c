#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd1 = open("in1", O_RDONLY, O_NONBLOCK);
	int fd2 = open("in2", O_RDONLY, O_NONBLOCK);
	
	int stop1 = 0, stop2 = 0;
	
	int sum = 0;
	
	for (;;) {
		fd_set fds;
		int maxfd;
		int res;
		char buf[1];

		FD_ZERO(&fds); // Clear FD set for select
		FD_SET(fd1, &fds);
		FD_SET(fd2, &fds);

		maxfd = fd1 > fd2 ? fd1 : fd2;

		select(maxfd + 1, &fds, NULL, NULL, NULL);

		
		if (FD_ISSET(fd1, &fds)) {
			// We can read from fd1
			res = read(fd1, buf, sizeof(buf));
			if (res > 0 && buf[0] != '\n') {
				//printf("Read %d bytes from channel1\n", res);
				int t;
				sscanf(buf, "%d", &t); 
				sum += t;
			} else if (res == 0) {
				stop1 = 1;
			}
		}
		
		if (FD_ISSET(fd2, &fds)) {		
			// We can read from fd2
			res = read(fd2, buf, sizeof(buf));
			if (res > 0 && buf[0] != '\n') {
				//printf("Read %d bytes from channel2\n", res);
				int t;
				sscanf(buf, "%d", &t); 
				sum += t;
			} else if (res == 0) {
				stop2 = 1;
			}
		}
		
		if (stop1 == 1 && stop2 == 1) {
			break;
		}
	}
	
	printf("%d\n", sum);
}