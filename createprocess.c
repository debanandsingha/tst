#include<stdio.h> // printf()
#include<stdlib.h> // exit()
#include<unistd.h> // fork()
#include<sys/wait.h> //wait()

void main(){
	int pid = fork();

	if(pid == 0){
		printf("Child Process running with PID: %d\n\n", getpid());
		exit(0);
	}else if(pid > 0){
		printf("Parent Process running with PID: %d\n", getpid());
		printf("It's Child's PID: %d\n\n", pid);
		wait(0);
	}else{
		printf("Process creatinn failed.\n");
		exit(-1);
	}
}
