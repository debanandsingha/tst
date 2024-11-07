//Sleep command using getpid
#include<stdio.h>
#include<unistd.h>

void main(){
	int pid = fork();

	if(pid==0){
		printf("\nChild Process\n");
		printf("Child PID: %d\n", getpid());
		printf("Parent PID: %d\n", getppid());
		sleep(5);

		printf("\nChild Process After 5s Sleep\n");
		printf("PID: %d\n", getpid());
		printf("PPID: %d\n\n", getppid());
	}else{
		printf("\nParent Process\n");
		sleep(10);
		printf("Child PID: %d\n", getpid());
		printf("Its parent PID: %d\n",getppid());
		printf("Parent Terminated\n");
	}
}
