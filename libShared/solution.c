#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <dlfcn.h>

int main(int c, char **v)
{
	char path[1024];
	strcpy(path, "./");
	strcat(path, v[1]);
	void *hdl = dlopen(path, RTLD_LAZY);
	int (*foo)(int) = (int (*)(int))dlsym(hdl, v[2]);
	printf("%d\n", foo(atoi(v[3])));
	return 0;
}

