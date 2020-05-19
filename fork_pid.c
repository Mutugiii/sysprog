#include <stdio.h>
#include <unistd.h>


/* simple program to view relationship btn pid processes work with fork
 * for fork - child gets a different pid
 * for pthread - child gets the same pid as parent
 * */

/* Run program with ps -ef | grep -i fork_pid  -> To find the process ids*/

/* You can kill the child process & the child will still be alive
 * though its parent gets owned by process 1 -> init process
 * kill -9 process_id   -> Command to kill the child
 * */

/* When the child process is killed it is retained in the system as a defunct/zombie function
 * the parent collects info of the childs exit status
 * so the child exits the system when the parent is killed.
 * */

/* A defunct/zombie process is a process which child process gets killed but lies in a dormant state, but its pid & other stuff are retained so that when the parent exits, the parent can rip off the pid -> Does a cleanup of pid */

int main()
{
    pid_t pid;

    if((pid = fork()) > 0)
    {
        sleep(3600);
    }
    else
    {
        sleep(3600);
    }

    return 0;
}
