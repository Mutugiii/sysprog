#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* Threads with context to execution -> Context switching */
/* In this program the threads run in parallel(with context switching) in respect to the cpu scheduler & jobs */
/* At first, the main thread print fewer lines as the text(code->var init) are executed*/

void *ThreadFunc(void *args)
{
    int i;
    for(i=0;i<25;++i)
    {
        printf("This is from thread i=%d\n", i);
    }
}

int main()
{
    pthread_t mythread;
    void *thread_result;
    int j;

    pthread_create(&mythread, NULL, ThreadFunc, NULL);
    
    for(j=0;j<25;++j)
    {
        printf("This is from parent or main thread j=%d\n", j);
    }

    pthread_join(mythread, &thread_result);
    return 0;
}
