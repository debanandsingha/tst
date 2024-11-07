#include <stdio.h>

struct Process {
    char name[5];
    int burstTime;
    int arrivalTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int n;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("%d) Enter Process Name: ", i + 1);
        scanf("%s", processes[i].name);
        printf(" -> Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf(" -> Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        printf(" -> Priority (lower value means higher priority): ");
        scanf("%d", &processes[i].priority);

        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = 0;
    }

    // Sort processes by arrival time and then by priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((processes[j].arrivalTime < processes[i].arrivalTime) ||
                (processes[j].arrivalTime == processes[i].arrivalTime &&
                 processes[j].priority < processes[i].priority)) {
                // Swap processes[i] and processes[j]
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int time = 0;
    printf("\n--- GANTT CHART ---\n");
    printf("0 | ");

    // Priority Scheduling Logic
    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrivalTime) {
            time = processes[i].arrivalTime; // Move time to the next process's arrival
        }

        // Calculate waiting and turnaround times
        processes[i].waitingTime = time - processes[i].arrivalTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;

        time += processes[i].burstTime;
        printf("%d %s | ", time, processes[i].name);
    }
    printf("\n");

    // Calculate averages
    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    // Print process details and averages
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].name,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].priority,
               processes[i].waitingTime,
               processes[i].turnaroundTime);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}

