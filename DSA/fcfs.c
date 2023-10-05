// Disk scheduling Algorithm FCFS

#include<stdio.h>
#include<stdlib.h>

void main(){

    int  rq[100],i,n,totalheadmoment=0,initial;
    printf("enter the number of requests \n");
    scanf("%d",&n);
    printf("enter the requests sequence \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);

    }
    printf("enter the initial head position");
    scanf("%d",&initial);
    for(i=0;i<n;i++)
    {
        totalheadmoment=totalheadmoment+abs(rq[i]-initial);
        initial=rq[i];

    }
    printf("total head moment is %d",totalheadmoment);


}