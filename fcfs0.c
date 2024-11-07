#include<stdio.h>

struct process{
 int id, ser, wait, tot;
}p[20];

void main(){
  int n, i, totalwait=0, totaltot=0;
  float avgwait, avgtot;
//Get the number of process
  printf("Enter the no. of process: ");
  scanf("%d",&n);

//Get the PID & Service Time of each process
  for(i=0; i<n; i++){
    printf("Enter PID: ");
    scanf("%d", &p[i].id);
    printf("Enter SERVICE time: ");
    scanf("%d", &p[i].ser);
  }

// Initially, waiting time of 1st process is 0 && total time is the service time
  p[0].wait=0;
  p[0].tot=p[0].ser;

// Calc waiting time && total time of remaining processes
  for(i=1; i<n; i++){
    p[i].wait=p[i-1].wait+p[i-1].ser;
    p[i].tot=p[i].wait+p[i].ser;
    totalwait += p[i].wait;
    totaltot += p[i].tot;
  }

// Add total time of 1st proess
  totaltot += p[1].tot;

// Calc Avg Wait &7 Avg Tot time
  avgwait = (float)totalwait/n;
  avgtot = (float)totaltot/n;

// Display process details
  printf("PID\tSER\tWAIT\tTOT\n");
  for(i=0; i<n; i++){
    printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].ser, p[i].wait, p[i].tot);
  }

// Gantt Chrt
  printf("Gantt Chart:\n");
  printf("|");
  for(i=0; i<n; i++){
    printf("P%d|",p[i].id);
  }
  printf("\n");
  printf("0  ");
  for(i=0; i<n; i++){
    printf("%d  ",p[i].tot);
  }
  printf("\n");

  printf("Avg. Wait time: %f\n", avgwait);
  printf("Avg. TOT time: %f", avgtot);
}
