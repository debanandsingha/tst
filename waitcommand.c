//To perform wait command using c program.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int i = 10;

void main(){
	int pid=fork();
	if(pid==0){
		printf("initial value of i: %d\n", i);
		i+=10;
		printf("value of i: %d\n", i);
		printf("Child Terminated\n");
	}else{
		wait(0);
		printf("Value of i in Parent Process: %d",i);
	}
}
