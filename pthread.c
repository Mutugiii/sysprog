#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* This program must be linked with the thread lib when compiling*/

/* Give function & run it in a separate thread */

/* Entire process gets forked from that process onwards while in pthread we name a func which will run as a context of a thread */

/* parent & thread have both same pid & ppid
 *ps -elf | grep ./pthread
 * */

void *ThreadFunc(void *args)
{
    int i;
    for(i=0;i<25;++i)
    {
        printf("This is from thread i=%d\n", i);
        sleep(1);
    }
}

int main()
{
    pthread_t mythread;
    void *thread_result;
    int j=0;
    
    /* Pass the ref to the thread | thread attributes/ way to start/ initialization with semapthore/ conditionals |  start_routine:the thread func above -> creates a container(with functions to be executed) | Arguments to pass(like func) */
    pthread_create(&mythread, NULL, ThreadFunc, NULL);

    for(j=0;j<25;j++)
    {
        /* Must put a sleep to allow the child thread sufficient time to execute before parent is terminated -> By child runs in context to parent */
        sleep(1);
        printf("This is from main or parent thread j=%d\n", j);
    }
    
    /* Forces parent to be alive until the child process completes, but also it won't be executed */
    pthread_join(mythread, &thread_result);
    return 0;
}
