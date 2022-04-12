#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>
int i;

void createChild(int signo){
	pid_t	pid;

	printf("SIGCLD received\n");

	if (signal(SIGINT, createChild) == SIG_ERR){
		perror("signal error");
    }

    pid = fork();
    if (pid < 0) {
		perror("fork error");
	}
    else if (pid == 0){	
		for(; i>0; i--){
            printf("%d seconds...\n",i);
            sleep(1);
        }
        sleep(1);
        exit(0);
	}
	else{
        exit(0);
    }
}

int main(int argc, char *argv[]){
    if(argc<2){
        printf("usage: ./tehtävä1 [1,2...]\n");
        exit(0);
    }
	if (signal(SIGINT, createChild) == SIG_ERR){
		perror("signal error");
    }

    i = atoi(argv[1]);
    for(; i>0; i--){
        printf("%d seconds...\n",i);
        sleep(1);
    }
	return 0;
}