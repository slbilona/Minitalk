#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

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

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
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
	int result = 0;
	int bin = ft_binaire('c', &result);
	printf("binaire : %d\n", bin);
	result = 0;
	int result2 = 0;
	printf("plus binaire : %c\n", ft_non_binaire(bin, &result2));
}

