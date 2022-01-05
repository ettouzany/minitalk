
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <libc.h>

char *str = NULL;

char *add_one()
{
    char *s;
    if (!str)
        return NULL;

    s = malloc(sizeof(char) * strlen(str) + 2);
    if (!s)
        return ((write(1, "notaloc\n", 8)), NULL);
    int i = 0;
    while (i < strlen(str))
    {
        s[i] = str[i];
        i++;
    }
    s[i++] = 0;
    s[i] = 0;
    return (free(str), s);
}

void    handler_sigusr(int sig, siginfo_t *info, void *context)
{
    static int count;
    static int j;
    if (count == 0 && j == 0)
    {
        str = malloc(sizeof(char)+1);
        if (!str)
            (write(1, "notaloc\n", 8));
        str[count] = 0;
        str[count+1] = 0;
    }
    if (str)
        str[count] = !(sig-30) ? str[count] << 1 : (str[count] << 1) + 1;
    j++;
    if (j > 7)
    {
        if (str[count] == 0)
        {
            write(1, str, count);
            if(info->si_pid)
                kill(info->si_pid, SIGUSR2);
            free(str);
            str = NULL;
            count = 0;
            j = 0;
        }
        else
        {
            count++;
            str = add_one();
        }
        j = 0;
    }
}
static void HandleHostSignal(void)
{
    struct sigaction satmp;
    satmp.sa_flags = SA_SIGINFO;
    satmp.sa_sigaction = handler_sigusr;

    sigaction(SIGUSR1, &satmp, NULL);
    sigaction(SIGUSR2, &satmp, NULL);
}
int main(void)
{
    pid_t pid;
    //struct sigaction new_action;
       // new_action.sa_flags = 0;
    //new_action.sa_handler = handler_sigusr;
    pid = getpid();
    printf("%d\n", pid);
    HandleHostSignal();
    // sigaction(SIGUSR1, &new_action,NULL);
    // sigaction(SIGUSR2, &new_action,NULL);
    while (1)
        usleep(1);
    
}
