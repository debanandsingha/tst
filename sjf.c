#include<stdio.h>

struct process{
  int id, ser, wait, tot;
}p[20], temp;

void main(){
  int n, i, j, t_wait=0, t_tot=0;
  float avg_wait, avg_tot;

  printf("Enter no. of process: ");
  scanf("%d", &n);

  for(i=0; i<n; i++){
    printf("%d) Enter PID: ", i+1);
    scanf("%d", &p[i].id);
    printf(" -> Enter SERVICE time: ");
    scanf("%d", &p[i].ser);
  }

// Sort processes based on Servie/Burst Time (SJF Scheduling)
  for(i=0; i<n-1; i++){
    for(j=i+1; j<n; j++){
      if(p[i].ser>p[j].ser){
        temp = p[i];
        p[i]=p[j];
        p[j]=temp;
      }
    }
  }

// Initializing 1st short process's  Waiting && Service Time
  p[0].wait = 0;
  p[0].tot = p[0].ser;

// Calc Waiting & Turn around time of remaining processes
  for(i=1; i<n; i++){
    p[i].wait = p[i-1].wait + p[i-1].ser;
    t_wait += p[i].wait;
    p[i].tot = p[i].wait + p[i].ser;
    t_tot += p[i].tot;
  }
t_tot += p[0].tot;

  printf("PID\tSER\tWAIT\tTOT\n");
  for(i=0; i<n; i++){
    printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].ser, p[i].wait, p[i].tot);
  }

  avg_wait = (float)t_wait / n;
  avg_tot = (float)t_tot /n ;

  printf("GANTT Chart: \n");
  printf("|");
  for(i=0; i<n; i++){
    printf("P%d|", p[i].id);
  }
  printf("\n");
  printf("0  ");
  for(i=0; i<n; i++){
    printf("%d  ", p[i].tot); // TOT is used for GANTT chart numbering
  }

  printf("\n\nTOTAL WAIT Time: %d\n", t_wait);
  printf("TOTAL TOT Time: %d\n", t_tot);
  printf("AVG. WAIT Time: %.2f\n", avg_wait);
  printf("AVG. TOT: %.2f", avg_tot);
}
