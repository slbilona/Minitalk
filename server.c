#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void ft_franchement_jsp(int sig)
{
	if(sig == SIGUSR1)
		printf("envoye\n");
	else if (sig == SIGUSR2)
		printf("recu\n");
}

void ft_peut_etre_que_je_sais()
{
	printf("encore\n");
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
	signal(SIGUSR1, ft_franchement_jsp);
	signal(SIGUSR2, ft_franchement_jsp);
	pause();
	return (0);
}