#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
int pid;
void from_char_to_bit(int c)
{
    printf("%d: \n", c);
    int i = 0;
    int j = 0;
    char str[8];

    while (c)
    {
        str[i] = c % 2;
        i++;
        c /= 2;
    }
    // printf("%s: \n", str);
    while (i + j < 8 && 0 > c)
    {
        kill(pid, SIGUSR1);
        j++;
        usleep(10);
    }
    while (i + j < 8 && 0 < c)
    {
        kill(pid, SIGUSR2);
        j++;
        usleep(10);
    }
    while (i--)
    {
        if (!str[i])
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(10);
    }
    // printf("\n");
}

void shit_tfker(char c)
{
    int i = 0;
    while (i++ < 8)
    {
        kill(pid, SIGUSR1 + (c & 1));
        c = c >> 1;
        usleep(10000);
    }
}

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc != 3)
    {
        printf("client: invalid arguments\n");
        exit(EXIT_FAILURE);
    }
    pid = atoi(argv[1]);
    while (i < strlen(argv[2]))
    {
        // from_char_to_bit((int)argv[2][i]);
        shit_tfker(argv[2][i]);
        i++;
    }
    usleep(10000);
    shit_tfker(0);
    return (0);
}