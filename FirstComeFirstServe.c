#include<stdio.h>
 
int main()
{
    int n;  
	int bt[20];								// burst time
	int wt[20],tat[20],avwt=0,avtat=0,i,j;
    
    
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
 
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("\nEnter Process Burst Time for P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    wt[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i] += bt[j];
    }
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i] = bt[i] + wt[i];			// turaroundTime = burstTime + waitTime
        avwt += wt[i];
        avtat += tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);
 
    return 0;
}
