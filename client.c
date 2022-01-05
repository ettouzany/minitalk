#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
int pid;
void shit_tfker(char c)
{
    int i = 8;
    while (i--)
    {
        kill(pid, SIGUSR1 + ((c >> i) & 1));
        
        usleep(200);
    }
}

void handler_sigusr(int sig, siginfo_t *info, void *context)
{
    if(sig == 31)
    {
        write(1, "good", 4);
    }
    else{
        write(1, "not good", 8);
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
int main(int argc, char *argv[])
{
    int i = 0;

    if (argc != 3)
    {
        printf("client: invalid arguments\n");
        exit(EXIT_FAILURE);
    }
     HandleHostSignal();
    pid = atoi(argv[1]);
    while (i < strlen(argv[2]))
    {
        // from_char_to_bit((int)argv[2][i]);
        shit_tfker(argv[2][i]);
        i++;
    }
    usleep(200);
    shit_tfker(0);
    //signal(SIGUSR2, handler_sigusr);
        usleep(200);

    //pause();
    //signal(SIGUSR2, handler_sigusr);
   
//    while (1)
//         usleep(1);
    return (0);
}