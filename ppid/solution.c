#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	pid_t pid = getpid();
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
			printf("%s\n", ppid);
		}
		fclose(f);
	}
}
