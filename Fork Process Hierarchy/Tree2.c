#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int first=0;
int first_m =0;

void advanced_fork(int n, int m);
void helper_fork();

int main(int argc, char*argv[])
{
    
    advanced_fork(atoi(argv[1]),atoi(argv[2]));
    return 0;
}


void advanced_fork(int n, int m)
    {
        first++;
        if(first == 1){
          first_m = m; 
        }
        if(m == 0 || n == 0)
            return ;

        int x = fork();
        if(x < 0)
        {
            printf("Fork failed\n");
            exit(1);
        }    

        else if(x == 0 )
        {
            
            printf("hello I am left child (pid:%d) and my parent is %d \n",(int) getpid(), (int) getppid());   
            advanced_fork(n,m-1);
            
            exit(0);
        }

        else 
        {
            wait(NULL);
            
            if(first_m == m)
            {
                
                helper_fork();
                advanced_fork(n-1,m);
            }
            exit(0);
        }
    }

    void helper_fork()
    {

        
        int x = fork();
        if(x < 0)
        {
            printf("Fork failed\n");
            exit(1);
        }    

        else if(x == 0)
        {
            
            printf("hello I am right child (pid:%d) and my parent is %d \n",(int) getpid(), (int) getppid());
    
        }
    

        else 
        {
            wait(NULL);

        }
        
    }
