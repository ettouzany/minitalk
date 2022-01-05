// #include <unistd.h>
// #include <stdio.h>
// #include <signal.h>
// int val = 10;

// void handler(int sig)
// {
//     val += 5;
// }

// int main(int argc, char const *argv[])
// {
//     printf("%d", (int)getpid());
//     signal(SIGCHLD, handler);
//     return 0;
// }

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <libc.h>

// void catcher(int signum)
// {
//     puts("inside catcher...");
// }

// void timestamp()
// {
//     time_t t;
//     time(&t);
//     printf("the time is %s", ctime(&t));
// }

// main()
// {
//     printf("%d\n", (int)getpid());
//     struct sigaction sigact;

//     // sigemptyset(&sigact.sa_mask);
//     // sigact.sa_flags = 0;
//     //  sigact.sa_handler = catcher;
//     sigaction(SIGUSR1, &sigact, NULL);

//     // alarm(10);
//     printf("before pause... ");
//     // timestamp();
//     pause();
//     if (1)
//         pause();
//     printf("after pause... ");
//     timestamp();
//     return (0);
// }

// server.c
// int count = 0;
// int j = 0;
// int convert(long long n)
// {
//     int dec = 0, i = 0, rem;
//     while (n != 0)
//     {
//         rem = n % 10;
//         n /= 10;
//         dec += rem * pow(2, i);
//         ++i;
//     }
//     str[i] = dec;
//     return dec;
// }
char *str = NULL;

char reverseBits(char n)
{

    char rev = 0;
    // traversing bits of 'n' from the right
    int i = 0;
    while (i++ < 8)
    {
        // bitwise left shift
        // 'rev' by 1
        rev <<= 1;

        // if current bit is '1'
        if ((n & 1))
            rev ^= 1;

        // bitwise right shift
        // 'n' by 1
        n >>= 1;
    }

    // required number
    return rev;
}

char *add_one()
{
    char *s;
    if (!str)
        return NULL;

    s = malloc(sizeof(char) * strlen(str) + 1);
    if (!s)
        return ((write(1, "notaloc\n", 8)), NULL);
    int i = 0;
    while (i < strlen(str))
    {
        s[i] = str[i];
        i++;
    }
    s[i] = 0;
    return (free(str), s);
}

void handler_sigusr(int signum)
{
    static int count;
    static int j;
    // char w = 48 + signum - 30;
    // write(1, &w, 1);
    if (count == 0 && j == 0)
    {
        str = malloc(sizeof(char));
        if (!str)
            (write(1, "notaloc\n", 8));
        str[count] = 0;
    }
    if (str)
        str[count] = !(signum) ? str[count] << 1 : (str[count] << 1) + 1;
    j++;
    if (j > 7)
    {
        // w = count + '0';
        if (str[count] == 0)
        {
            write(1, str, count);
            // write(1, "\n", 1);
            free(str);
            str = NULL;
            count = 0;
            j = 0;
        }
        else
        {
            str[count] = reverseBits(str[count]);
            count++;
            str = add_one();
        }
        j = 0;

        // str[0] >> 5 != 6 || str[0] >> 4 != 14 || str[0] >> 3 != 60
        // if (!(str[0] >> 7))
        // {
        //     write(1, &str, 1);
        //     count = 0;
        //     str[count] = 0;
        // }
        // else if (str[0] >> 5 == 6 && str[1] >> 6 == 2)
        // {
        //     write(1, &str, 2);
        //     str[count] = 0;
        //     while (count)
        //     {
        //         str[--count] = 0;
        //     }
        // }
        // else if (str[0] >> 4 == 14 && str[1] >> 6 == 2 && str[2] >> 6 == 2)
        // {
        //     write(1, &str, 3);
        //     str[count] = 0;
        //     while (count)
        //     {
        //         str[--count] = 0;
        //     }
        // }
        // else if ((str[0] >> 4 == 60 && str[1] >> 6 == 2 && str[2] >> 6 == 2 && str[3] >> 6 == 2) || count == 3)
        // {
        //     write(1, &str, 4);
        //     str[count] = 0;
        //     while (count)
        //     {
        //         str[--count] = 0;
        //     }
        // }
        // else
        // {
        //     count++;
        // }
    }
}
// void handler_sigusr2(int signum)
// {
//     str[count] = '0';
//     i++;
//     // write(1, "|", 1);
//     if (i == 8)
//     {
//         convert(atoi(str));
//         write(1, &c, 1);
//         i = 0;
//     }
// }

int main(void)
{
    // pid_t pid;
    //  printf("%d", reverseBits(50));
    // struct sigaction new_action;
    // new_action.sa_handler = handler_sigusr;
    // pid = getpid();
    // printf("%d\n", pid);
    // sigaction(SIGUSR1, &new_action, NULL);
    // sigaction(SIGUSR2, &new_action, NULL);
    // while (1)
    // usleep(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
    handler_sigusr(1);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(0);
    handler_sigusr(1);
}
