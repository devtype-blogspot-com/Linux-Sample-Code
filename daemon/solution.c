#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <syslog.h>

int main() {
	pid_t pid;

	// Создание процесса
	pid = fork();

	if (pid != 0) exit(EXIT_SUCCESS);

	// Перейти в корневой каталог
	chdir("/");

	// Установить новый идентификатор сессии
	setsid();

	printf("%d\n", getpid());
	
	// Закрыть файлы стандартного I/O
	fclose(stdin);
	fclose(stdout);
	fclose(stderr);

	while (1) {
		sleep(32);
	}

	return EXIT_SUCCESS;
}
