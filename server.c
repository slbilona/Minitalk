#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "./Ma_Libft/libft.h"

void ft_franchement_jsp(int sig)
{
	if(sig == SIGUSR1)
		printf("0\n");
	else if (sig == SIGUSR2)
		printf("1\n");
}

char ft_non_binaire(int c, int *result)
{
	if(c == 0 || (c >= 1 && c <= 9))
	{
		if(c == 1)
			*result = *result * 2 + 1;
		else
			*result = *result * 2;
	}
	else
	{
		*result = ft_non_binaire(c / 10, result);
		*result = ft_non_binaire(c % 10, result);
	}
	return (*result);
}

int main()
{
	int pid_t = getpid();
	printf("PID : %d\n", pid_t);
	while(1)
	{
		signal(SIGUSR1, ft_franchement_jsp);
		signal(SIGUSR2, ft_franchement_jsp);
		usleep(1);
	}
	pause();
	return (0);
}