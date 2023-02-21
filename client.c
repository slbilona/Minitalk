#include <sys/types.h>
#include <signal.h>
#include <stdio.h>

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

void ft_binaire(int c)
{
	int i;
	char result[30];
	char *base = "01";

	i = 0;
	if(c >= 0 && c <= 1)
	{
		result[i] = base[c];
		i++;
	}
	else if (c > 1)
	{
		ft_binaire(c / 2);
		ft_binaire(c % 2);
	}
	printf("%s\n", result);
}


int main()
{
	// int pid;

	// if(ac == 3)
	// {
	// 	pid = ft_atoi(av[1]);
	// 	if(pid == -1)
	// 	{
	// 		printf("error\n");
	// 		return (0);
	// 	}
	// 	kill(pid, SIGUSR1);
	// }
	ft_binaire('s');
}

