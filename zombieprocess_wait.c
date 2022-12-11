#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
// parent duty is to destry its child entry after child is executed
// if even after child process is executed it's entry remains in the system
int main()
{
    pid_t p = fork();

    if(p)
    {   
        wait(NULL); // to avoid getting zombie process
        sleep(3);
        printf("I am parent , my id %d\n",getpid());
        printf("my child %d\n",p);
    }
    else
    {
        printf("i am child, my id : %d\n",getpid());
        printf("my parent id is: %d\n",getppid());
    }
}
//gcc zombieprocess.c && ./a.out &ps
// defunct in output means that parent doesn't know that child process is created