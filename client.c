/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:31:59 by ilselbon          #+#    #+#             */
/*   Updated: 2023/03/06 22:37:11 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_booleen = 0;

void	ft_plus_de_place(char *test, int pid)
{
	int	i;

	i = 0;
	while (test[i] && g_booleen == 0)
	{
		if (test[i] == '0')
		{
			g_booleen = 1;
			if (kill(pid, SIGUSR1))
			{
				ft_printf("Mauvais PID.\n");
				return ;
			}
			while (g_booleen)
				;
		}
		if (test[i] == '1')
		{
			g_booleen = 1;
			if (kill(pid, SIGUSR2))
			{
				ft_printf("Mauvais PID.\n");
				return ;
			}
			while (g_booleen)
				;
		}
		i++;
	}
	free(test);
}

void	ft_fin(int pid)
{
	int	i;

	i = 0;
	while (i <= 6 && g_booleen == 0)
	{
		i++;
		g_booleen = 1;
		if (kill(pid, SIGUSR1))
		{
			ft_printf("Mauvais PID.\n");
			return ;
		}
		while (g_booleen)
			;
	}
}

void	ft_yacine(int pid, char *str)
{
	char	*test;
	int		result;
	int		i;
	int		j;

	j = 0;
	while (str[j])
	{
		result = 0;
		i = 0;
		test = ft_itoa(ft_binaire(str[j], &result));
		if (ft_strlen(test) < 7)
		{
			while (i < (7 - (int)ft_strlen(test)) && g_booleen == 0)
			{
				g_booleen = 1;
				i++;
				if (kill(pid, SIGUSR1))
				{
					ft_printf("Mauvais PID.\n");
					return ;
				}
				while (g_booleen)
					;
			}
		}
		ft_plus_de_place(test, pid);
		j++;
	}
	ft_fin(pid);
}

void	ft_principale(int ref)
{
	if (ref == 10)
		g_booleen = 0;
}

int	main(int ac, char **av)
{
	struct sigaction	ba = {0};
	int					pid;

	pid = ft_atoi(av[1]);
	ba.sa_handler = ft_principale;
	sigaction(SIGUSR1, &ba, NULL);
	if (ac == 3)
	{
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
