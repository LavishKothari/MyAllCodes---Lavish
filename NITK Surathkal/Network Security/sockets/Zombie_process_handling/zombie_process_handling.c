#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>
#include<string.h>
void handler(int sig)
{
    int pid;
    int status;
    while((pid=waitpid((pid_t)-1,&status,WNOHANG))>0)
    	printf("Reaping process with pid:%d\n",pid);
}

int main()
{
	int fid;
    struct sigaction sa; 
    memset((char *)&sa, 0, sizeof(sa));

    sa.sa_handler=&handler;
    //sa.sa_handler=SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags=SA_RESTART | SA_NOCLDSTOP;
    printf("Init Process ID:%d\n",getpid());

    if (sigaction(SIGCHLD, &sa, 0) == -1)
    {
        perror(0);
        exit(1);
    }

    fid=fork();
    
    if(fid<0)
        printf("Error while forking \n");
    else if(fid==0)
    {
        printf("Child Process\n");
        printf("Parent Process ID:%d\n",getppid());
        printf("Child Process ID:%d\n\n",getpid());
         
        exit(1);
    }
    else
    {
        printf("Parent Process\n");
        printf("Current Process ID:%d\n\n",getpid());
        printf("Child Process ID:%d\n\n",getpid());
        
        //sleep(10000);
    }
    return 0;
}
