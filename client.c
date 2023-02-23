#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "./Ma_Libft/libft.h"

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

char *ft_strcat(char *str, char c)
{
	int i;
	char *new;
	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while(str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = 0;
	free(str);
	return (new);
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

int main(int ac, char **av)
{
	char *test;
	int result;
	int i;
	int pid;
	int j;

	j = 0;
	result = 0;
	i = 0;
	if(ac == 3)
	{
		pid = ft_atoi(av[1]);
		if(pid == -1)
		{
			printf("error\n");
			return (0);
		}
		while(av[2][j])
		{
			result = 0;
			i = 0;
			test = ft_itoa(ft_binaire(av[2][j], &result));
			printf("%s\n", test);
			if(ft_strlen(test) < 7)
			{
				while(i < (7 - (int)ft_strlen(test)))
				{
					kill(pid, SIGUSR1);
					usleep(1);
					i++;
				}
			}
			i = 0;
			while(test[i])
			{
				if(test[i] == '0')
					kill(pid, SIGUSR1);
				else if (test[i] == '1')
					kill(pid, SIGUSR2);
				i++;
				usleep(1);
			}
			usleep(1);
			free(test);
			j++;
		}
		i = 8;
		while(i)
		{
			kill(pid, SIGUSR1);
			usleep(1);
			i--;
		}
	}
}

