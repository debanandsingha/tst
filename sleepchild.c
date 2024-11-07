#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void main(){
	int pid = fork();

	if(pid == 0){
		sleep(2);
		printf("Child Running with PID: %d\n", getpid());
		exit(1);
	}else if(pid > 0){
		printf("Parent Running with PID: %d\n", getpid());
		exit(1);
	}else{
		printf("Process Crreation Failed!\n");
		exit(-1);
	}
}
