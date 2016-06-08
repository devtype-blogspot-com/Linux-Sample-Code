#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

int main() {
	DIR *p = opendir("/proc");
	struct dirent *d;
	long id;

	char path[64], line[128], *n;
	FILE *s;

	int answer = 0;

	while (d = readdir(p)) {
		if (!isdigit(*d->d_name)) continue;
		id = strtol(d->d_name, NULL, 10);
		
		snprintf(path, 64, "/proc/%ld/status", id);
		s = fopen(path, "r");
		if (!s) continue;

		while (fgets(line, 128, s)) {
			if (strncmp(line, "Name:", 5) != 0) continue;
			n = line + 6;
			while (isspace(*n)) ++n;
			//printf("%6ld %s", id, n);
			if (strncmp(n, "genenv", 6) == 0) ++answer;
			//if (strncmp(n, "bash", 4) == 0) ++answer;
		}

		fclose(s);
	}
	closedir(p);

	printf("%d\n", answer);
}
