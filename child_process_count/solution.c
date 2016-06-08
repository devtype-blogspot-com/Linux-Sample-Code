#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int cnt_childs(pid_t ppid)
{
	int result = 0;
	char cmd[32];
	sprintf(cmd, "ps -o pid= --ppid %d", ppid);
	FILE *f = popen(cmd, "r");
	pid_t pid;
	while (fscanf(f, "%d", &pid) != EOF) {
		result += 1 + cnt_childs(pid);
	}
	pclose(f);
	return result;
}

int main(int argc, char *argv[]) {
	printf("%d\n", cnt_childs(atoi(argv[1])) + 1);
}

