#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "./Ma_Libft/libft.h"

char lettre[8];

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

void ft_franchement_jsp()
{
	int i;
	int charac;
	i = 0;
	lettre[7] = 0;
	charac = 0;
	while(lettre[i])
		i++;
	lettre[i] = '0';
	if(ft_strlen(lettre) == 7)
	{
		ft_non_binaire(ft_atoi(lettre), &charac);
		printf("%c\n", charac);
		i = 7;
		while(i >= 0)
			lettre[i--] = 0;
	}
}

void ft_peut_etre_que_si()
{
	int i;
	int charac;

	i = 0;
	lettre[7] = 0;
	charac = 0;
	while(lettre[i])
		i++;
	lettre[i] = '1';
	if(ft_strlen(lettre) == 7)
	{
		ft_non_binaire(ft_atoi(lettre), &charac);
		printf("%c\n", charac);
		i = 7;
		while(i >= 0)
			lettre[i--] = 0;
	}
}

int main()
{
	int pid_t = getpid();
	printf("PID : %d\n", pid_t);
	while(1)
	{
		signal(SIGUSR1, ft_franchement_jsp);
		signal(SIGUSR2, ft_peut_etre_que_si);
	}
	pause();
	return (0);
}