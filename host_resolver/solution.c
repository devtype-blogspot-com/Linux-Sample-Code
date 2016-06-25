#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	struct hostent *he = gethostbyname(argv[1]);

	char **p = he->h_aliases;
	for (; *p; p++) {
		printf("%s\n", *p);
	}

	return 0;
}
