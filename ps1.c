#include <stdio.h>

int main() {
    int i, j, n, t;
    int turn[20], burst[20], p[20], wt[20], c[20];
    float await, aturn, twait = 0, tturn = 0;

    // Input the number of processes
    printf("\nEnter the value of n: ");
    scanf("%d", &n);

    // Input process numbers, burst time, and arrival time
    printf("\nEnter the process number, burst time, and priority(low value - high priority):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        scanf("%d", &burst[i]);
        scanf("%d", &p[i]);
    }

    // Sorting based on priority
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                // Swap priority
                t = p[i];
                p[i] = p[j];
                p[j] = t;

                // Swap burst time
                t = burst[i];
                burst[i] = burst[j];
                burst[j] = t;

                // Swap process number
                t = c[i];
                c[i] = c[j];
                c[j] = t;
            }
        }
    }

    // Calculate waiting time and turnaround time
    for (i = 0; i < n; i++) {
        if (i == 0) {
            wt[i] = 0;
            turn[i] = burst[i];
        } else {
            turn[i] = turn[i - 1] + burst[i];
            wt[i] = turn[i] - burst[i];
        }
        twait += wt[i];
        tturn += turn[i];
    }

    // Calculate average waiting time and turnaround time
    await = twait / n;
    aturn = tturn / n;

    // Output process details and average times
    printf("\npno\tbtime\tatime\twtime\tttime");
    for (i = 0; i < n; i++) {
        printf("\n%d\t%d\t%d\t%d\t%d", c[i], burst[i], p[i], wt[i], turn[i]);
    }
    printf("\nThe average waiting time is: %f", await);
    printf("\nThe average turnaround time is: %f", aturn);

    return 0;
}
