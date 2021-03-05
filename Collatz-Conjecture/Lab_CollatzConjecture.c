/* 
   Using the fork() system call that generates this sequence (if n = 35,
   35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1) in the child 
   process, utilizing the given Collatz conjecture algorithm. Have the
   parent invoke the wait() call to wait for the child process to
   complete before exiting the program. Perform necessary error checking
   to ensure that a positive integer is passed on the command line.
*/ 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int Collatz(int num)
{
    // check error condition
    if(num <= 0)
    {
        printf("No sequence. %d is not positive", num);
        return 0;
    }

    int count = 0;
    while(count != 1)
    {
        // equal to 1
        if(num == 1)      
        {
            printf("%d ",num);
            return 0;          
        }
        // even condition
        else if(num % 2 == 0)
        {
            printf("%d ",num);
            num /= 2;          
        }
        // odd condition  
        else               
        {
            printf("%d ",num);
            num = num * 3 + 1;
        }               
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int num, stat_loc = 0;
    pid_t pid;
    num = atoi(argv[1]);
    // fork function                 
    pid = fork();
    // create child                   
    if(pid == -1)                      
    {
        printf("Child Process was not created");
    }
    else if(pid == 0)      
    {
        printf("The generated sequence for %d is: ", num);
        Collatz(num);
    }   
    else if(pid > 0)      
    {
        wait(&stat_loc);
        printf("\n");
    }                          
}
