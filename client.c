#include <sys/types.h>
#include <signal.h>
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

//ajouter les verif apres les kill
void ft_yacine(int pid,char *str)
{
	char *test;
	int result;
	int i;
	int j;
	

	j = 0;
	while(str[j])
	{
		result = 0;
		i = 0;
		test = ft_itoa(ft_binaire(str[j], &result));
		if(ft_strlen(test) < 7)
		{
			while(i < (7 - (int)ft_strlen(test)) && booleen == 0)
			{
				booleen = 1;
				i++;
				if(kill(pid, SIGUSR1))
					ft_printf("error\n");
				while(booleen);
			}
		}
		i = 0;
		while(test[i] && booleen == 0)
		{
			
			if(test[i] == '0')
			{
				booleen = 1;
				kill(pid, SIGUSR1);
				while(booleen);
			}
				
			if(test[i] == '1')
			{
				booleen = 1;
				kill(pid, SIGUSR2);
				while(booleen);
			}
			i++;
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
	
	int					pid;

	pid = ft_atoi(av[1]);
	
	struct sigaction	ba = {0};

	ba.sa_handler = ft_principale;
	sigaction(SIGUSR1, &ba, NULL);

	if (ac == 3)
	{
		if(pid == -1 || pid == 0)
		{
			ft_printf("error\n");
			return (0);
		}
		ft_yacine(pid, av[2]);
	}
	else
	{
		ft_printf("error\n");
	}
}