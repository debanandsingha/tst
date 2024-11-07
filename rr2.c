#include<stdio.h>

struct process{
	char pname[5];
	int arrivalT, burstT, remainingT, turnaroundT, waitingT;
}p[10];

void main(){
	int n, tq, time=0, totalTOT=0, totalWT=0, completedProcess=0;
	printf("Total No. of Processes: ");
	scanf("%d",&n);
	// Input & Initialization
	for(int i=0; i<n; i++){
		printf("%d) Enter Process Name: ",i+1);
		scanf("%s", p[i].pname);
		printf(" -> Arrival Time: ");
		scanf("%d", &p[i].arrivalT);
		printf(" -> Burst Time: ");
		scanf("%d", &p[i].burstT);

		p[i].remainingT=p[i].burstT;
		p[i].turnaroundT = p[i].waitingT = 0;
	}
	printf("Enter Time Quantum: ");
	scanf("%d", &tq);

	printf("\n--- GANTT CHART ---\n");
	printf("0 | ");
	//Till All process finishes
	while(completedProcess < n){
		int flag=1;//No process ready for execution

		for(int i=0; i<n; i++){
			if(p[i].remainingT>0 && p[i].arrivalT <= time ){
				flag=0;//Process ready for execution

				if(p[i].remainingT > tq){
					time += tq;
					p[i].remainingT -= tq;
				}else{
					time += p[i].remainingT; //Process Finished
					p[i].remainingT = 0; 
					p[i].turnaroundT = time - p[i].arrivalT;
					p[i].waitingT = p[i].turnaroundT - p[i].burstT;
					totalTOT += p[i].turnaroundT;
					totalWT += p[i].waitingT;
					completedProcess++;
				}
				printf("%d %s | ", time, p[i].pname);
			}
		}
		// No process ready, Increment Time
		if(flag)
			time++;
	}
	printf("\n");

	float avgWaitingTime = (float)totalWT / n;
	float avgTurnAroundTime = (float)totalTOT / n;

	printf("Process\tArrival\tBurst\tTurnaround\tWaiting\n");
	for(int i=0; i<n; i++){
		printf("%s\t%d\t%d\t%d\t%d\n", p[i].pname, p[i].arrivalT, p[i].burstT, p[i].turnaroundT, p[i].waitingT);
	}

	printf("\nAVG. WAITING TIME: %.2f", avgWaitingTime);
	printf("\nAVG. TOT: %.2f", avgTurnAroundTime);

}
