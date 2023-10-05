#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0; // Waiting time for the first process is 0

    // Calculate waiting time
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);

    // Find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Display processes along with their waiting and turnaround times
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    // Calculate average waiting time and average turnaround time
    printf("\nAverage waiting time = %.2f", (float)total_wt / n);
    printf("\nAverage turnaround time = %.2f", (float)total_tat / n);
}

// Driver code
int main() {
    int processes[] = {1, 2, 3}; // Process IDs
    int n = sizeof processes / sizeof processes[0]; // Number of processes

    int burst_time[] = {24, 3, 3}; // Burst time of all processes

    findAverageTime(processes, n, burst_time);

    return 0;
}
