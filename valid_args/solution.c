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
	opterr = 0;
	int opindex = 0;
	int opchar = 0;
	struct option opts[] = {
		{"query", required_argument, 0, 'q'},
                {"longinformationrequest", no_argument, 0, 'i'},
                {"version", no_argument, 0, 'v'}
	};
	while (-1 != (opchar = getopt_long(c, v, "q:iv", opts, &opindex))) {
	 // printf("opchar = %c\n", opchar);
	 switch (opchar) {
		case 'q':
			break;
		case 'i':
			break;
		case 'v':
			break;
		default:
			printf("-\n");
			return 0;
			break;
	 }
	}
	printf("+\n");
	return 0;
}

