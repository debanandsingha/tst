#include<stdio.h>
#include<unistd.h> //gives access to UNIX/POSIX OS API functions

void main(){
   fork();
   printf("Hello! PID=%d\n", getpid());
}
