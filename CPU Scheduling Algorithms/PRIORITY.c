#include <stdio.h>
int main() 
{
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg = 0.0, tatavg = 0.0;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    for(i = 0; i < n; i++)
     {
        p[i] = i; // Process IDs (0, 1, 2, ...)
        printf("Enter the Burst Time & Priority of Process %d: ", i);
        scanf("%d %d", &bt[i], &pri[i]);
    }

    // Sorting processes based on priority (ascending order)
    for(i = 0; i < n; i++) 
    {
        for(k = i + 1; k < n; k++) 
        {
            if(pri[i] > pri[k]) 
            {
                // Swap Process IDs
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                // Swap Burst Times
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap Priorities
                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }
        }
    }

    // Initial values for Waiting Time and Turnaround Time
    wt[0] = 0;   // Waiting time for the first process is 0
    tat[0] = bt[0];  // Turnaround time for the first process is its burst time
    wtavg = 0;
    tatavg = bt[0];

    // Calculate waiting time and turnaround time for each process
    for(i = 1; i < n; i++) 
    {
        wt[i] = wt[i - 1] + bt[i - 1];   // Waiting time is previous waiting time + previous burst time
        tat[i] = tat[i - 1] + bt[i];     // Turnaround time is previous turnaround time + current burst time
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Display the table of processes, their burst times, waiting times, and turnaround times
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) 
    {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    // Calculate and display the average waiting time and average turnaround time
    printf("\nAverage Waiting Time is: %f", wtavg / n);
    printf("\nAverage Turnaround Time is: %f", tatavg / n);

    return 0;
}
