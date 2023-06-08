#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;
    pid = vfork();
    if(pid==-1)
    {
        perror(" vfork ");
        return 1;

    }
    else if(pid==0)
    {
        printf("child process: Hello. I'm the child \n");
        printf("child process: My PD is %d \n",getpid());
         printf("child process: My parent PID is %d \n",getppid());
         _exit(0);
    }
    else{
       printf("parent process: Hello .I'm the parent \n");
        printf("parent process: My PD is %d \n",getpid());
         printf("parent process: My child PID is %d \n",getppid());
         int status;
         waitpid(pid,&status,0);
         if(WIFEXITED(status))
         {
            printf("parent process:child process terminated normally \n");
            
            
         }
         else
         {
            printf("parent process child process terminatd abnormally \n ");
            }
         }
    return 0;
    }