#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid_t = getpid();
    printf("PID : %d\n", pid_t);
    
    return (0);
}