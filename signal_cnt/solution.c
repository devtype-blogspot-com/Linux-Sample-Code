#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int stop = 0;
int s1 = 0, s2 = 0;

void mysignal_handler1(int signalno) {
	s1 += 1;
}

void mysignal_handler2(int signalno) {
	s2 += 1;
}

void mysignal_handler3(int signalno) {
	stop = 1;
}

int main() {
	signal(SIGUSR1 , mysignal_handler1);
	signal(SIGUSR2 , mysignal_handler2);
	signal(SIGTERM , mysignal_handler3);
	while (stop == 0) {
		usleep(100000);
	}
	printf("%d %d\n", s1, s2);
	return 0;
}

