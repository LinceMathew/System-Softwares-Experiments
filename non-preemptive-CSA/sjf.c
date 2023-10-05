// Shortest Job Next (SJN) or Shortest Job First (SJF) scheduling algorithm
#include<stdio.h>
void main()
{
    int i,j,n,p[10],bt[10],wt[10],tat[10],twt=0,ttat=0,t,flag;
    float awt,atat;
    //inserting Number of processes
    printf("Enter the number of processes :");
    scanf("%d",&n);
    //inserting PID and Its Brust Time;;
    printf("Enter the PID and BT of each processes :");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&p[i],&bt[i]);
    }
    //sorting the PID and BT in asending order
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
        {
            if(bt[j]>bt[j+1])
            {
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;

                flag=1;

            }
        }
        if(flag==0)
            break;
    }
    //calculating the WT and TAT
    wt[0]=0;
    tat[0] = bt[0]+wt[0];
    //printf("%d",&tat[0]);
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        //twt = twt+wt[i];
        tat[i]=bt[i]+wt[i];

    }
    for(i=0;i<n;i++) 
    {
        twt=twt+wt[i];
        ttat=twt+tat[i];
    }
    awt=(float)twt/(float)n;
    //awt=(float)awt;
    atat=(float)ttat/(float)n;
    //printing result
    printf("PID\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Average WT = %f\nAverage TAT = %f",awt,atat);
}