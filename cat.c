#include <stdio.h>
#include <stdlib.h>

/* simple cat command using getline api - Check getline manpage */

int main(int argc, char *argv[])
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if(argc != 2)
    {
        printf("Please provide a file to print out its contents\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    /* If file contents is null -> program exits */
    if (fp == NULL)
        exit(EXIT_FAILURE);

    //printf("Character read:\t\t Contents\n");
    /* If getline call return -1 there is no data */
    while((read = getline(&line, &len, fp)) != -1) {
        /* printf("%zu :\t", read);    //How many bytes it has read - Prints the char reads */
        printf("%s", line);         //Actual data
    }
    
    /* Must free up because of double pointer line which performs a malloc */
    if(line)
        free(line);
    
    fclose(fp);
    exit(EXIT_SUCCESS);
}
