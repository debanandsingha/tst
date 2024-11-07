#include <stdio.h>

struct Process {
    char name[5];
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    int remainingTime;
};

int main() {
    int n, tq, time = 0, completedProcesses = 0;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
	printf("%d) Enter Process Name: ", i+1);
	scanf("%s", processes[i].name);
	printf(" -> Arrival Time: ");
	scanf("%d", &processes[i].arrivalTime);
	printf(" -> Burst Time: ");
	scanf("%d",&processes[i].burstTime);

        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    printf("\n--- GANTT CHART ---\n");
    printf("0 | ");

    // Round Robin Scheduling
    while (completedProcesses < n) {
        int allProcessesChecked = 1;  // To check if any process is ready for execution

        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0 && processes[i].arrivalTime <= time) {
                allProcessesChecked = 0; // At least one process is ready

                if (processes[i].remainingTime > tq) {
                    time += tq; // Increase time by time quantum
                    processes[i].remainingTime -= tq;
                } else {
                    time += processes[i].remainingTime; // Finish the process
                    processes[i].remainingTime = 0;
                    processes[i].turnaroundTime = time - processes[i].arrivalTime;
                    processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
                    totalTurnaroundTime += processes[i].turnaroundTime;
                    totalWaitingTime += processes[i].waitingTime;
                    completedProcesses++;
                }
                printf("%d %s | ", time, processes[i].name);
            }
        }

        // If no process was ready, increment the time
        if (allProcessesChecked) {
            time++;
        }
    }

    printf("\n");

    // Calculate averages
    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    // Print process details and averages
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
