#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void recursive_fork(int n);


int main(int argc, char*argv[])
{
    
    recursive_fork(atoi(argv[1]));
    return 0;
}


 void recursive_fork(int n)
{
    
    if(n == 0 )
        return ;

    int x = fork();
    int root =getpid();
    if(x<0)
    {
        printf("Fork failed\n");
        exit(1);
    }    

    else if(x == 0)
    {
        
        {
            printf("hello I am right child (pid:%d) and my parent is %d \n",(int) getpid(), (int) getppid());
            
            if(n ==1)
            {
                    int last = fork();
                    if( last == 0)
                {
                    printf("hello I am left child (pid:%d) and my parent is %d \n",(int) getpid(), root);
                    exit(0);
                    
                }

            }
            
            recursive_fork(n-1);
        }

    }

    else 
    {
        int t = wait(NULL);
        {
            printf("hello, I am parent of %d (t:%d) (pid:%d)\n",x, t, (int) getpid());
            
            int y = fork();
            if( y == 0)
            {
                printf("hello I am left child (pid:%d) and my parent is %d \n",(int) getpid(), (int) getppid());
                exit(0);
            }
            exit(0);
            
        }
    }
    
}   

    