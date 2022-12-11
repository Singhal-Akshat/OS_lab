#include <stdio.h>
#include<limits.h>
typedef struct
{
    int id;
    int burst_time;
    int arr_time;

}process;
int main() 
{
  
      int  smallest, time, n;
      double wait_time = 0, turnaround_time = 0, end;
      float average_waiting_time, average_turnaround_time;

      printf("Enter the Total Number of Processes: ");
      scanf("%d", &n); 
      process p[n+1];
      int temp[n];
      for(int i = 0; i < n; i++) {

        printf("the arrival time for process P%d : ", i + 1);
        scanf("%d", &p[i].arr_time);
        scanf("%d", &p[i].burst_time);
        temp[i] = p[i].burst_time;
        p[i].id =i;

    }
      p[n].burst_time = INT_MAX;
  int count=0;
      printf("Process\t||\tArrival Time\t||\tCompletion time\n");
      for(time = 0; count < n; time++)
      {
            smallest = n;
            for (int i = 0; i < n; i++) {
            if (p[i].arr_time <= time && p[i].burst_time > 0 && p[i].burst_time < p[smallest].burst_time)
                  smallest = i;
            }
            
            p[smallest].burst_time--;
            // printf("Current Process %d, Remaining time: %d\n",smallest+1, p[smallest].burst_time);
            if(p[smallest].burst_time == 0)
            {     printf("P[%d]\t||\t%d\t\t||\t%d\n", smallest + 1,p[smallest].arr_time,time+1);
                  count++;
                  end = time + 1;
                  wait_time = wait_time + end - p[smallest].arr_time - temp[smallest];
                  turnaround_time = turnaround_time + end - p[smallest].arr_time;
            }
      }
      average_waiting_time = wait_time / n; 
      average_turnaround_time = turnaround_time / n;
      printf("\nAverage Waiting Time: %lf", average_waiting_time);
      printf("\nAverage Turnaround Time: %lf", average_turnaround_time);
      return 0;
}