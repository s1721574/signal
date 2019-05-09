#include <stdio.h>
#include <signal.h>

int main(void) {

	sigset_t set;

	sigemptyset(&set);
	sigaddset(&set,SIGINT);

	switch(sigismember(&set, SIGINT)) {
		case 1 : printf("SIGINT는 포함되어 있습니다.\n");
				 break;
		case 0 : printf("SIGINT 없습니다.\n");
				 break;
		default : printf("sigismember() 호출 실패.\n");
				}
	sigdelset(&set, SIGINT);

	switch(sigismember(&set, SIGINT)) {
		case 1 : printf("SIGINT는 포함되어 있습니다.\n");
				 break;
		case 0 : printf("SIGINT 없습니다.\n");
				 break;
		default : printf("sigismember() 호출 실패.\n");
			
}
	return 0;
}

