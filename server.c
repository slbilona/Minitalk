#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void ft_franchement_jsp()
{
	printf("envoye\n");
}

void ft_peut_etre_que_je_sais()
{
	printf("encore\n");
}

int main()
{
	int pid_t = getpid();
	printf("PID : %d\n", pid_t);
	signal(SIGUSR1, ft_franchement_jsp);
	pause();
	return (0);
}