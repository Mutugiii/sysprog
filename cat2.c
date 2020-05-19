#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/* Implementation of cat command using read calls & buffers */

int main(int argc, char *argv[])
{
    int fd = -1;                // file descriptor - Unique handler to identify file associated with a screen
    char buffer[4096] = {0};    // The bigger the buffer size, the faster the process
    int ret = 0;

    if(argc != 2)
    {
        printf("Please provide the filename as argument to read\n");
        exit(EXIT_FAILURE);
    }
    
    /* Open a file using readonly */
    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Error in opening the file error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    /* Provide file, buffer & how much data to read. Return number of bytes it has read; if return 0 -> End of a file; return -1 -> Encountered an error; Always leave a char extra for null termination */
    while(ret = read(fd, (void *)buffer, sizeof(buffer)-1 ) > 0)
    {
        printf("%s", buffer);
        /* Prevent buffer from polluting */
        memset(buffer, 0, sizeof(buffer));
    }

    close(fd);
    
    return EXIT_SUCCESS;
}
