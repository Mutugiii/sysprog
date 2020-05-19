#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

/* simple implementation of find command in Unix systems */

void listdir(const char *pathname)
{
    DIR *dp;
    struct dirent *dirp;
    char PATH[259] = {0};
    /*  By default max path in a linux sys is 256, we set ours to 259 for -1 in sieof path operation, null char used as part of copying file & null char in snprintf operation - Leads to 256 */


    if((dp = opendir(pathname)) == NULL)
        return;

    while((dirp = readdir(dp)) != NULL)
    {
        /* d_type indicates file type: DT_DIR is a macro of the d_type that indicates that it is a directory - check manpage of readdir */
        if(dirp->d_type == DT_DIR)
        {
            /* Compare the dir name with the current dir or parent dir(2 dots) */
            if( (strcmp(dirp->d_name, ".") == 0) || (strcmp(dirp->d_name, "..") ==0) )
                /* We continue since we are sure if it is a current or single dir, there is  nothing further */
                continue;      

            /* We print dir & have to go into directory recursively */
            printf("%s%s\n", pathname, dirp->d_name);
            /* We need to also print the path of the recursive dir */
            snprintf(PATH, sizeof(PATH)-1, "%s%s/", pathname, dirp->d_name);
            listdir(PATH);
        }
        else
        {
            printf("%s%s\n", pathname, dirp->d_name);
        }
    }
    closedir(dp);
}   

/* argc is the number os strings pointed by argv  int argc & char *argv[] are meant to collect command line args*/
int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc != 2)
    {
        printf("Please provide a directory to list out\n");
        exit(1);
    }

    listdir(argv[1]);

    exit(0);
}
