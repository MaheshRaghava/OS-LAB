#include <stdio.h>
int main()
{
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg = 0.0, tatavg = 0.0;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    // Input burst times for each process
    for(i = 0; i < n; i++) 
    {
        p[i] = i;  // Assign process ID (0 to n-1)
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
    }

    // Sorting the burst times in ascending order (Shortest Job First)
    for(i = 0; i < n; i++) {
        for(k = i + 1; k < n; k++)
        {
            if(bt[i] > bt[k])
            {
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap process IDs accordingly to maintain correct mapping
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

    // Calculate waiting times and turnaround times
    wt[0] = 0;  // Waiting time for the first process is always 0
    tat[0] = bt[0];  // Turnaround time for the first process is its burst time

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];  // Waiting time for each process
        tat[i] = tat[i - 1] + bt[i];    // Turnaround time for each process
    }

    // Calculate average waiting time and average turnaround time
    for(i = 0; i < n; i++)
    {
        wtavg += wt[i]; 
        tatavg += tat[i];
    }

    // Displaying the result
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++)
    {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %f", wtavg / n);
    printf("\nAverage Turnaround Time: %f", tatavg / n);
    return 0;
}
