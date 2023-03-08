/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:32:02 by ilselbon          #+#    #+#             */
/*   Updated: 2023/03/08 16:30:45 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_binaire(int c, int *result)
{
	char	*base;

	base = "01";
	if (c == 0 || c == 1)
		*result = *result * 10 + (base[c] - 48);
	else
	{
		*result = ft_binaire(c / 2, result);
		*result = ft_binaire(c % 2, result);
	}
	return (*result);
}

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

int	main(int ac, char **av)
{
	struct sigaction	ba;
	int					pid;

	if (ac == 3)
	{
		ft_memset(&ba, 0, sizeof(ba));
		pid = ft_atoi(av[1]);
		ba.sa_handler = ft_principale;
		sigaction(SIGUSR1, &ba, NULL);
		if (pid == -1 || pid == 0)
		{
			ft_printf("Mauvais PID.\n");
			return (0);
		}
		ft_yacine(pid, av[2]);
	}
	else
		ft_printf("Error\n");
}
