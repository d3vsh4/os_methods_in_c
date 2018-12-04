#include<stdio.h>
int main()
{
    int n, wt[10], tat[10], bt[10], total_wt = 0, total_tat = 0;
    printf("enter the no of process between 1 to 10 ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter the burst time for the process pid[%d] ",i+1);
        scanf("%d",&bt[i]);
    }
    //
    //
    //
    // waiting time for first process is 0
    wt[0] = 0;
    // calculating waiting time
    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
    //Display processes along with all details
    printf("Processes   Burst time   Waiting time   Turn around time\n");
    // Calculate total waiting time and total turn around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("   %d ",(i+1));
        printf("       %d ", bt[i] );
        printf("       %d",wt[i] );
        printf("       %d\n",tat[i] );
    }
    float awt=(float)total_wt / (float)n;
    float atat=(float)total_tat / (float)n;
    printf("Average waiting time = %f",awt);
    printf("\n");
    printf("Average turn around time = %f ",atat);

    return 0;
}
