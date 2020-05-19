#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

/* Simple implementation of `ls` command; Lists all the directories provided as argument; Also shows hidden dirs */

int main(int argc, char *argv[])
{
    /* Opaque DS */
    DIR *dp;

    /* Contains file info like name, inode & offset */
    struct dirent *dirp;
    
    /* Must contain 1 arguments */
    if(argc < 1)
    {
        //printf("Please provide the directory to list\n");
        exit(1);
    }
    else if(argc == 2)
    {
        dp = opendir(argv[1]);
    }
    else
    {
        dp = opendir(".");
    }
    
    /* opendir is used to open a directory - In unix systems both files & directories work like directories */
    if(dp == NULL)
    {
        printf("Cannot open directory error=%s\n", strerror(errno));
        exit(1);
    }
    
    /* readdir to read directory contents - dirp has the directory name stored using d_name property */
    while(( dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    closedir(dp);
    exit(0);
}
