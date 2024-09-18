#include<stdio.h>
#define max 5
int main()
{
int i,j,n,t,p[max],bt[max],pr[max],wt[max],tat[max],total_wt=0,total_tat=0;
float awt=0,atat=0;
printf("Enter the number of processes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the process number\n");
scanf("%d",&p[i]);
printf("Enter the burst time of process\n");
scanf("%d",&bt[i]);
printf("Enter the priority pf the process\n");
scanf("%d",&pr[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n-i-1;j++)
{
 if(pr[j]>pr[j+1])
 {
   t=pr[j];
   pr[j]=pr[j+1];
   pr[j+1]=t;
   t=bt[j];
   bt[j]=bt[j+1];
   bt[j+1]=t;
   t=p[j];
   p[j]=p[j+1];
   p[j+1]=t;
   }
  }
 }
 printf("Process id\tburst time\tpriority\twaiting time\ttat\t\n");
 for(i=0;i<n;i++)
 { 
   wt[i]=0;
   tat[i]=0;
   for(j=0;j<i;j++)
   wt[i]=wt[i]+bt[j];
   tat[i]=wt[i]+bt[j];
   total_wt=total_wt+wt[i];
   total_tat=total_tat+tat[i];
   printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],pr[i],wt[i],tat[i]);
   }
   awt=(float)total_wt/n;
   atat=(float)total_tat/n;
   printf("The average waiting time=%f\n",awt);
   printf("The average turn around time=%f\n",atat);
 }
   
   
   
   
