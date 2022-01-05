#include <unistd.h>

int main(int argc, char const *argv[])
{
    // handler_sigusr(31);
    // handler_sigusr(31);
    // handler_sigusr(31);
    // handler_sigusr(31);
    // handler_sigusr(31);
    // handler_sigusr(31);
    // handler_sigusr(31);
    // handler_sigusr(31);
    char str[] = {-16, -97, -104, -126};
    write(1, str, 4);
    return 0;
}