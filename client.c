#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "./Ma_Libft/libft.h"

int booleen = 0;

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	result = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

int ft_binaire(int c, int *result)
{
	char *base = "01";
	if(c == 0 || c == 1)
		*result = *result * 10 + (base[c] - 48);
	else
	{
		*result = ft_binaire(c / 2, result);
		*result = ft_binaire(c % 2, result);
	}
	return (*result);
}

void ft_yacine(int pid,char *str)
{
	char *test;
	int result;
	int i;
	int j;
	

	j = 0;
	result = 0;
	i = 0;
	while(str[j])
	{
		result = 0;
		i = 0;
		test = ft_itoa(ft_binaire(str[j], &result));
		//printf("test : %s\n", test);
		if(ft_strlen(test) < 7)
		{
			while(i < (7 - (int)ft_strlen(test)) && booleen == 0)
			{
				booleen = 1;
				i++;
				kill(pid, SIGUSR1);
				while(booleen);
			}
		}
		i = 0;
		while(test[i] && booleen == 0)
		{
			//printf("booleen : %d\n", booleen);
			if(test[i] == '0')
				kill(pid, SIGUSR1);
			else if (test[i] == '1')
				kill(pid, SIGUSR2);
			i++;
			booleen = 1;
			while(booleen);
		}
		free(test);
		j++;
	}
	i = 0;
	while(i <= 6 && booleen == 0)
	{
		i++;
		booleen = 1;
		kill(pid, SIGUSR1);
		while(booleen);
	}
}

void ft_principale(int ref)
{
	if(ref == 10)
	{
		booleen = 0;
	}
}

int main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	pid = ft_atoi(av[1]);
	sa.sa_handler = ft_principale;
	sigaction(SIGUSR1, &sa, NULL);

	if (ac == 3)
	{
		if(pid == -1)
		{
			printf("error\n");
			return (0);
		}
		ft_yacine(pid, av[2]);
	}
	else
	{
		ft_printf("error\n");
	}
}