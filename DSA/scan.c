// Disk Scheduling Algorithm scan
#include<stdio.h>
#include<stdlib.h>
void main(){
   int rq[100],i,j,n,totalheadmoment=0,initial,size;
   printf("enter the number of requests\n");
   scanf("%d",&n);
   printf("enter the requests sequences\n");
   for(i=0;i<n;i++)
   {
       scanf("%d",&rq[i]);

   }
    printf("enter the initial head position\n");
    scanf("%d",&initial);
    printf("enter the total disk size\n");
    scanf("%d",&size);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(rq[j]>rq[j+1])
                {
                    int temp;
                    temp=rq[j];
                    rq[j]=rq[j+1];
                    rq[j+1]=temp;
                }
        }
    }

int index;
for(i=0;i<n;i++)
    {
    if(initial<rq[i])
        {
            index=i;
            break;

        }
    
    }
for(i=index;i<n;i++)
{
    totalheadmoment=totalheadmoment+abs(rq[i]-initial);
    initial=rq[i];
}
totalheadmoment=totalheadmoment+abs(size-rq[i-1]-1);
printf("%d",abs(size-rq[i-1]-1));
initial=size-1;
printf("%d",initial);
for(i=index;i>=0;i--)
    {
    totalheadmoment=totalheadmoment+abs(rq[i]-initial);
    initial=rq[i];
    }

    printf("total head movement is %d",totalheadmoment);
}