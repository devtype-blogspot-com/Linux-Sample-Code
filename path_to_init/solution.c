#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void foo(pid_t pid) {
	printf("%d\n", pid);
	if (pid == 1) return;

	char buff[1024];
	sprintf(buff, "/proc/%d/stat", pid);
	FILE *f = fopen(buff, "r");
	if (f) {
		size_t sz = fread(buff, sizeof(char), sizeof(buff), f);
		if (sz > 0) {
			strtok(buff, " ");
			strtok(NULL, " ");
			strtok(NULL, " ");
			char *ppid = strtok(NULL, " ");
			foo(atoi(ppid));
		}
		fclose(f);
	}
}

int main(int c, char **v) {
	foo(atoi(v[1]));
}

