#include<stdio.h>

int main(int argc, char *argv[]) {
	FILE *p;
	char path[1024];
	sprintf(path, "%s %s", argv[1], argv[2]);
	p = popen(path, "r");

	if (!p) {
		fprintf(stderr, "Error opening pipe!\n");
		return 1;
	}

	int answer = 0;
	while (!feof(p)) {
		char c = fgetc(p);
		if (c == '0') answer++;
	}

	if (pclose(p) == -1) {
		fprintf(stderr," Error!\n");
		return 1;
	}
	
	printf("%d\n", answer);

	return 0;
}