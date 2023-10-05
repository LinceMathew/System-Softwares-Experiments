// Priority Scheduling algorithm with preemption
#include<stdio.h>

void main()
{
    int n, i, j, time, total = 0;
    int priority[10], burst_time[10], arrival_time[10], remaining_time[10];
    int min, current, flag = 0;
    float waiting_time = 0, turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time, burst time and priority for each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &arrival_time[i], &burst_time[i], &priority[i]);
        remaining_time[i] = burst_time[i];
    }

    printf("\nGantt Chart:\n");
    for(time = 0; ; time++)
    {
        min = 9;
        for(i = 0; i < n; i++)
        {
            if(arrival_time[i] <= time && priority[i] < priority[min] && remaining_time[i] > 0)
                min = i;
        }

        printf("%d -> ", min + 1);
        remaining_time[min]--;

        if(remaining_time[min] == 0)
        {
            total++;
            flag = 1;
            waiting_time += time + 1 - arrival_time[min] - burst_time[min];
            turnaround_time += time + 1 - arrival_time[min];
        }

        if(total == n)
            break;

        if(flag == 1)
        {
            flag = 0;
            continue;
        }
    }

    printf("\n\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%.2f\t\t%.2f\n", i + 1, arrival_time[i], burst_time[i], priority[i], time - arrival_time[i] - burst_time[i] + 1, time - arrival_time[i] + 1);
        waiting_time += time - arrival_time[i] - burst_time[i] + 1;
        turnaround_time += time - arrival_time[i] + 1;
    }

    printf("\nAverage Waiting Time: %.2f", waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", turnaround_time / n);
}
