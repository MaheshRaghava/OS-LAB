#include <stdio.h>
int main() 
{
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max;
    float awt = 0, att = 0, temp = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    for(i = 0; i < n; i++) 
    {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i]; // Copying burst times to compute turnaround time
    }

    printf("Enter the size of time slice: ");
    scanf("%d", &t);

    // Finding maximum burst time to calculate the total rounds
    max = bu[0];
    for(i = 1; i < n; i++)
     {
        if(max < bu[i])
        {
            max = bu[i];
        }
    }

    // Round Robin Scheduling
    for(j = 0; j < (max / t) + 1; j++) 
    {
        for(i = 0; i < n; i++) 
        {
            if(bu[i] != 0) 
            {
                if(bu[i] <= t) 
                {
                    tat[i] = temp + bu[i]; // Turnaround Time
                    temp += bu[i];          // Increment total time by burst time
                    bu[i] = 0;              // Process is completed
                } else {
                    bu[i] -= t;             // Deduct time slice
                    temp += t;              // Increment total time by time slice
                }
            }
        }
    }

    // Calculating Waiting Time (Waiting Time = Turnaround Time - Burst Time)
    for(i = 0; i < n; i++) 
    {
        wa[i] = tat[i] - ct[i]; // Waiting Time
        att += tat[i];           // Total Turnaround Time
        awt += wa[i];            // Total Waiting Time
    }

    // Display the average turnaround time and average waiting time
    printf("The Average Turnaround Time is: %f\n", att / n);
    printf("The Average Waiting Time is: %f\n", awt / n);

    // Display process details
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("\t%d \t %d \t\t %d \t\t %d\n", i + 1, ct[i], wa[i], tat[i]);
    }

    return 0;
}
