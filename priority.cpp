#include<stdio.h>
#include<limits.h>
typedef struct
{
    int id;
    int burst_time;
    int arr_time;
    int priority;

}process;

int main()
{
   
    int waiting[10],turnaround[10],completion[10];
    int i,j,smallest,count=0,time,n;
    double avg=0,tt=0,end;
    printf("\nEnter the number of Processes: ");
    scanf("%d",&n);

    process p[n+1];
    for(i=0;i<n;i++)
   {
      printf("\nEnter arrival time, burst time, priority of process: ");
      scanf("%d%d%d",&p[i].arr_time,&p[i].burst_time,&p[i].priority);
      p[i].id = i;
   }
  

    // pr[9]=-1;
    p[n].priority = -1;
    printf("Process\t||\tArrival Time\t||\tCompletion time\n");
    for(time=0;count!=n;)
    {
        smallest=n;
        for(i=0;i<n;i++)
        {
            if(p[i].arr_time<=time && p[i].priority>p[smallest].priority && p[i].burst_time>0)
                smallest=i;
        }
        time+=p[smallest].burst_time;
        // printf("time is : %d\n", time);
        count++;
        end=time+1;
        completion[smallest] = time;
        waiting[smallest] = time -p[smallest].arr_time - p[smallest].burst_time;
        turnaround[smallest] = time - p[smallest].arr_time;
        printf("Process %d, arrival: %d, completion: %d\n",smallest+1,p[smallest].arr_time, completion[smallest]);
        p[smallest].burst_time=-1;
    }
    
    for(i=0;i<n;i++)
    {
        // printf("p")i+1)"\t\t")x[i])"\t\t")a[i])"\t\t")waiting[i])"\t\t")turnaround[i])"\t\t")completion[i])"\t\t")pr[i])endl;
        // printf("Waiting : %d, turnaround : %d\n", waiting[i], turnaround[i]);
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    printf("\nAverage waiting time = %f",avg/(float)n);
    printf("\nAverage Turnaround time =  %f",tt/(float)n);
}