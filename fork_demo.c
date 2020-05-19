#include <stdio.h>
#include <unistd.h>

/* spawning child processes using fork  - forks off a process at a certain point */
/* Entire process gets forked from that process onwards while in pthread we name a func which will run as a context of a thread */

/* Fork uses the internal Clone api - pthread also uses it */

int main()
{
    pid_t pid;

    if( (pid = fork()) > 0) // parent process
    {
        printf("This is the parent process\n");
    }
    else    // child process - =0
    {
        printf("This is printed from the context of child process\n");
    }
}
