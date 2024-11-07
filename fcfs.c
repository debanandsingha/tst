#include <stdio.h>

// ser: burst time or service time

struct process {
    int id, wait, ser, tottime;
} p[20];

int main() {
    int i, n, totalwait = 0, totalser = 0;
    float avwait, avturn;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process ID and service time for each process
    for (i = 0; i < n; i++) {
        printf("Enter process ID: ");
        scanf("%d", &p[i].id);
        printf("Enter process service time: ");
        scanf("%d", &p[i].ser);
    }

    // Set waiting time for the first process
    p[0].wait = 0;
    p[0].tottime = p[0].ser;

    // Calculate waiting time and total time for each process
    for (i = 1; i < n; i++) {
        p[i].wait = p[i - 1].wait + p[i - 1].ser;
        totalwait += p[i].wait;
        p[i].tottime = p[i].wait + p[i].ser;
        totalser += p[i].tottime;
    }

    // Include the total service time of the first process
    totalser += p[0].tottime;

    // Calculate average waiting time and average turn-around time
    avwait = (float)totalwait / n;
    avturn = (float)totalser / n;

    // Display process details
    printf("Id\tService\tWait\tTotal\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].ser, p[i].wait, p[i].tottime);
    }

    // Display average times
    printf("Average waiting time: %.2f\n", avwait);
    printf("Average turn-around time: %.2f\n", avturn);

    // Display Gantt Chart
    printf("\nGantt Chart:\n");
    printf(" |");
    for (i = 0; i < n; i++) {
        printf(" P%d |", p[i].id);
    }
    printf("\n");

    // Print the time markers below the Gantt Chart
    printf("0");
    for (i = 0; i < n; i++) {
        printf("\t%d", p[i].tottime);
    }
    printf("\n");

    return 0;
}
