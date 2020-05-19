#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Simple implementation of the cp command */

int main(int argc, char *argv[])
{
    int fd_in = -1;
    int fd_out = -1;

    char buffer[10] = {0};
    int ret = 0;
        int retw = 0;
        char *INPUT_FILENAME;
        char *OUTPUT_FILENAME;

    /* 2 arguments must be provided */
    if(argc != 3)
    {
        printf("Please provide the filename as argument to read and for writing to!\n");
        exit(EXIT_FAILURE);
    }

        INPUT_FILENAME = argv[1];
        OUTPUT_FILENAME = argv[2];

    fd_in = open(INPUT_FILENAME, O_RDONLY);

    if(fd_in == -1)
    {
        printf("Error in opening the file error: %s", strerror(errno) );
        exit(EXIT_FAILURE);
    }

    /* Formats that could be used in opening the file */
    /* Read write mode is a must | truncate -> If file has content, remove and write a fresh | create -> If file does not exit, create a new one | nums -> mode permissions: user can read & execute, group & other can read */
    //fd_out = open(OUTPUT_FILENAME, O_RDWR | O_TRUNC | O_CREAT, 0544);a
    /* */
    /* S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH -> equivalent of 0544 : They are sub-options of the create*/
    fd_out = open(OUTPUT_FILENAME, O_TRUNC | O_APPEND | O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
    
    if(fd_out == -1)
    {
        printf("Please provide the filename as argument to read and for writing to!\n");
        close(fd_in); //As it is already opened
        exit(EXIT_FAILURE);
    }

    while( (ret = read(fd_in, (void*)buffer, sizeof(buffer)-1)) > 0)
    {
        /* Pass the amount of data returned to the buffer size of write operation - Can still pass buffer size though, but this assures amount being read and written are the same */
        retw = write(fd_out, buffer, ret);

        if(retw != ret)
        {
            printf("Error in writing complete data error: %s", strerror(errno));
            
				/* Close & clean up in case of error, as there may be mem leakege if the ret & retw don't match */
				close(fd_out);
				close(fd_in);
				exit(EXIT_FAILURE);
        }
        memset(buffer, 0, sizeof(buffer));
    }

    close(fd_in);
    close(fd_out);

    return EXIT_SUCCESS;
}
