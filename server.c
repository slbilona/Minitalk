#include "server.h"
#include <signal.h>

char lettre[8];

char *ft_strcat(char *str, char c)
{
	int i;
	char *new;

	i = 0;
	if(!str)
	{
		new = malloc(sizeof(char) * 2);
		new[i] = c;
		new[i + 1] = 0;
	}
	else
	{
		new = malloc(sizeof(char) * (ft_strlen(str) + 2));
		while(str[i])
		{
			new[i] = str[i];
			i++;
		}
		new[i] = c;
		new[i + 1] = 0;
		free(str);
	}
	return (new);
}

char *ft_chaine_de_charac(char c)
{
	static char *chaine;

	if(c == 0)
	{
		ft_printf("%s\n", chaine);
		free(chaine);
		chaine = NULL;
	}
	else
	{
		chaine = ft_strcat(chaine, c);
		//printf("%c\n", c);
	}
	return (chaine);
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

// void ft_franchement_jsp()
// {
// 	int i;
// 	int charac;

// 	i = 0;
// 	lettre[7] = 0;
// 	charac = 0;
// 	while(lettre[i])
// 		i++;
// 	lettre[i] = '0';
// 	if(i == 6)
// 	{
// 		ft_non_binaire(ft_atoi(lettre), &charac);
// 		ft_chaine_de_charac(charac);
// 		//printf("%c\n", charac);
// 		i = 0;
// 		while(i < 7)
// 			lettre[i++] = 0;
// 	}
// }

// void ft_peut_etre_que_si()
// {
// 	int i;
// 	int charac;

// 	i = 0;
// 	lettre[7] = 0;
// 	charac = 0;
// 	while(lettre[i])
// 		i++;
// 	lettre[i] = '1';
// 	if(i == 6)
// 	{
// 		ft_non_binaire(ft_atoi(lettre), &charac);
// 		ft_chaine_de_charac(charac);
// 		//printf("%c\n", charac);
// 		i = 0;
// 		while(i < 7)
// 			lettre[i++] = 0;
// 	}
// }

void ft_test(int ref, siginfo_t *siginfo, void *context)
{
	int pid;
	int i;
	int charac;
	
	(void) context;
	(void) siginfo;
	pid = siginfo->si_pid;
	i = 0;
	lettre[7] = 0;
	charac = 0;
	while(lettre[i])
		i++;
	if(ref == SIGUSR1)
		lettre[i] = '0';
	else if (ref == SIGUSR2)
		lettre[i] = '1';
	if (i == 6)
	{
		ft_non_binaire(ft_atoi(lettre), &charac);
		ft_chaine_de_charac(charac);
		i = 0;
		while(i < 7)
			lettre[i++] = 0;
	}
	kill(pid, SIGUSR1);
}

int main()
{
	struct sigaction sa;

	sa.sa_sigaction = ft_test;
	sa.sa_flags = SA_SIGINFO;


	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	ft_printf("PID : %d\n", getpid());
	while(1);
	pause();
	return (0);
}