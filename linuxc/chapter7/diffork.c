#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int globVar=5;

int main()
{
    pid_t pid;
    int var=1,i;

    printf("fork is different with vfork\n");

    pid=fork();
  //pid=vfork();
    switch(pid)
    {
        case 0:
            i=3;
            while(i-->0)
            {
                printf("Child Process is Runing\n");
                globVar++;
                var++;
                sleep(1);
            }
            printf("Child's globVar=%d ,var=%d\n",globVar,var);
            exit(0);
        case -1:
            printf("Fork Process Error");
            exit(0);
        default:
            i=5;
            while(i-->0)
            {
                printf("Parent Process is runing\n");
                globVar++;
                var++;
                sleep(1);
            }
            printf("Parent's globVar=%d,var=%d\n",globVar,var);
            exit(0);
    }
}

