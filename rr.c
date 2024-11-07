#include<stdio.h>

// boolean: tracks if a process is executed at least once
// flagcnt: indicates if the process is added to gantt chart && processed correctly. Prevents DOUBLE COUNTING/INCORRECT CALC.
struct roundRobin{
  int burst, burst1, arrivt, wtime, endtime, boolean, flagcnt;
  char pname[5];
}p[5];

int n, tq; // n: no of processes && tq: Time Quantum

void input();
void initialize();
void calculate();
void display();

void main(){
  input();
  initialize();
}

void input(){
  int i;
  printf("Enter Total No. of Processes: ");
  scanf("%d",&n);

  for(i=0; i<n; i++){
    printf("%d) Enter Process Name: ",i+1);
    scanf("%s", p[i].pname); // INPUT in CHAR ARRAY
    printf(" -> Arrival Time: ");
    scanf("%d", &p[i].arrivt);
    printf(" -> Burst Time: ");
    scanf("%d", &p[i].burst);
  }

  printf("Enter TIME QUANTUM: ");
  scanf("%d",&tq);
}

void initialize(){
  for(int i=0; i<n; i++){
    p[i].burst1=p[i].burst;
    p[i].wtime = p[i].endtime = p[i].boolean = p[i].flagcnt = 0; // assignment: RIGHT to LEFT
  }
}

void calculate(){

}
