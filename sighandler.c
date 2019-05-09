#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigint_handler(int signo) {
	int ndx;


	printf("\nctrl-c 누르셨습니다.\n");
	printf("또 누르면 종료됩니다.\n");

	for(ndx = 10; 0< ndx; ndx--) {
		printf("%d초 남았습니다.\n",ndx);
		sleep(1);
}
}
int main(void) {

	struct sigaction act;

	act.sa_handler = sigint_handler; // 시그널 핸들러 지정
	sigfillset(&act.sa_mask);; // 시그널 처리 중 블록될 시그널은 없음

	sigaction(SIGINT,&act,NULL);

	while(1) {
	printf("쿨쿨\n");
	sleep(1);
	}

	return(0);
}
