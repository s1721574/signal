#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler(int signo) {
	printf("\nctrl-c 누르셨습니다.\n");
	printf("또 누르면 종료됩니다.\n");
	sigaction(SIGINT,&act_old,NULL);
}

int main(void) {

	act_new.sa_handler = sigint_handler; // 시그널 핸들러 지정
	sigemptyset(&act_new.sa_mask); // 시그널 처리 중 블록될 시그널은 없음

	// sigint 를 지정하면서 act_old 이전 정보를 구한다.
	sigaction(SIGINT, &act_new,&act_old);

	while(1) {
	printf("쿨쿨\n");
	sleep(1);
	}

	return(0);
}
