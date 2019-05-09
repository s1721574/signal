#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void(*abc)(int);

void sigint_handler(int signo) {
	printf("\nctrl-c 누름\n");
	printf("또 누르면 종료.\n");
	signal(SIGINT,abc);
}

int main(void) {
	abc = signal(SIGINT, sigint_handler);

	while(1) {
	printf("쿨쿨, %dn",getpid());
	sleep(1);
	}

	return(0);
}
