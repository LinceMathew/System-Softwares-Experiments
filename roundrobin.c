#include<stdio.h>
void main()
 {
     int n,i,j,qt,bt[10],ct[10],at[10],rt[10],time=0,tot_rem=0,tat[10],wt[10],tot_tat,tot_wt;
     float avg_tat,avg_wt;
     printf("\nEnter the quantum time for scheduling: ");
     scanf("%d",&qt);

    printf("\nEnter the no of process : ");
    scanf("%d",&n);

     //scanning the burst time of processes
     printf("Enter the burst time for the process in their order of arrival :\n");
    for(i=0;i<n;i++)
     {
         scanf("%d",&bt[i]);
     }
     //copying the burst time array to remaining-time array for accounting purpose
     for(i=0;i<n;i++)
     {
         rt[i]=bt[i];
     }

    //calculating the total remaining time
     tot_rem=0;
    for(i=0;i<n;i++)
    {
         tot_rem += rt[i];
    }

    //calculating completion time for each process
    i=0;
    while(tot_rem >0)
    {
    // if there exist some remaining time then go for calculation
        if(rt[i] >0)
         {
              // there is a chance where reamining time can be less than quantum time
            if(rt[i]<qt)
            {
                time += rt[i];
                rt[i]=0;
             }
             else
             {
                 time += qt;
                  rt[i] -= qt;
             }
             // to know whether process has completed its execution
             if(rt[i] == 0)
             {
                 ct[i]=time;
             }
        }
         // incrementing process index where they are in a cyclic queue
         i++;
         i %= n;
         //checking if all process has completed its execution or not
         tot_rem = 0;
        for(j=0;j<n;j++)
        {
            tot_rem += rt[j];
        }
       }
 for(i=0;i<n;i++)
    {
        tat[i] = ct[i] - 0;
         wt[i] = tat[i] - bt[i];
    }
 // Printing the result
 printf("\nPID\tBT\tCT\tTAT\tWT\n");
 for(i=0;i<n;i++)
    {
         printf("\n%d\t%d\t%d\t%d\t%d",i+1,bt[i],ct[i],tat[i],wt[i]);
    }
 //Printing avg_tat and avg_wt
tot_tat=0;
tot_wt=0;
 for(i=0;i<n;i++)
     {
         tot_tat += tat[i];
        tot_wt += wt[i];
    }
avg_tat = (float)tot_tat/(float)n;
avg_wt= (float)tot_wt/(float)n;
printf("\nAverage TAT = %f and Average WT = %f",avg_tat,avg_wt);

}