#include<stdio.h>
#include<unistd.h>

void main(){
  int pid = fork();
  if(pid == 0){
    printf("Child Process is Runing!\n"); 
  }else if(pid > 0){
    printf("Parent Process is Running!\n");
    printf("Child Process PID = %d", pid);
  }else{
    printf("Child Process Creation Failed!\n");
  }
}
