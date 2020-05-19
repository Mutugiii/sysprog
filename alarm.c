#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h> //Give access to General Purpose Functions - system()

/* Constants to Change Color Output!*/
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RED     "\x1b[31m"


/*Generic Function that handles the signal after call is made*/
void sig_handler(int signum)
{
    /*perform anything in the signal handler*/
    printf("Alarm delivered is %d\n", signum);
    system("telnet towel.blinkenlights.nl");
    system("sudo apt-get update && sudo apt-get install sl -y");
    system("sudo apt-get install cowsay -y && sudo apt install toilet -y");
    system("sudo apt-get install cmatrix && sudo apt-get install fortune -y");
    system("clear; sl; sleep 3");
    system("clear; fortune | cowsay; sleep 3");
    system("toilet I Love Linux...;sleep 3");
    system("clear; cmatrix");
    exit(0);
}

int main()
{
    alarm(5);
    signal(SIGALRM, sig_handler);

    /*start executing from this line if not exited in signal_handler*/
    for(;;) //Infinite Loop
        sleep(1);

    return 0;
}
