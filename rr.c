#include<stdio.h>
int main()
{
int bt[10],at[10],wt[10],tat[10],i,n,count=0,time_quantum,t=0,rem_bt[10],flag=0;
float total_wt,total_tat=0;
printf("Enter Total Processes:\t");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter Burst Time:\n");
scanf("%d",&bt[i]);
}
printf("Enter Time quantum:\t");
scanf("%d",&time_quantum);
for(i=0;i<n;i++)
rem_bt[i]=bt[i];
t=0;
while(1)
{
flag=1;
for(i=0;i<n;i++)
{
if(rem_bt[i]>0)
{
flag=0;
if(rem_bt[i]>time_quantum)
{
t+=time_quantum;
rem_bt[i]=rem_bt[i]-time_quantum;
}
else
{
t=t+rem_bt[i];
wt[i]=t-bt[i];
rem_bt[i]=0;
}
}
}
if(flag==1)
break;
}
for(i=0;i<n;i++)
tat[i]=bt[i]+wt[i];
printf("\nProcess BT\tWT\tTAT\n");
for(i=0;i<n;i++)
printf("\n%d\t%d\t%d\t%d\t",i+1,bt[i],wt[i],tat[i]);
for(i=0;i<n;i++)
{
total_wt=total_wt+wt[i];
total_tat=total_tat+tat[i];
}
printf("\n\nAverage Waiting Time=%f",total_wt/n);
printf("\nAverage Turnaround Time=%f",total_tat/n);
}
