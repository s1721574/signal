#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int counter = 0;

void sig_handler(int signo) {
	printf(" 알람 : %d \n", counter++);
}

int main(void) {
	int i = 0;

	signal(SIGALRM, sig_handler);
	alarm(5);

	while(i<10) {
		printf("%d\n", i);
		sleep(1);
		i++;
	}

	return 0;
}
