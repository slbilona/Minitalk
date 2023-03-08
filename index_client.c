/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:31:59 by ilselbon          #+#    #+#             */
/*   Updated: 2023/03/08 15:24:55 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_booleen = 0;

int	ft_plus_de_place(char *test, int pid)
{
	int	i;

	i = 0;
	while (test[i] && g_booleen == 0)
	{
		g_booleen = 1;
		if (test[i] == '0')
		{
			if (kill(pid, SIGUSR1))
				return (free(test), ft_printf("Mauvais PID.\n"));
		}
		if (test[i] == '1')
		{
			if (kill(pid, SIGUSR2))
				return (free(test), ft_printf("Mauvais PID.\n"));
		}
		while (g_booleen)
			;
		i++;
	}
	free(test);
	return (0);
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

void	ft_trop_court(int pid, char *test)
{
	int	i;

	i = 0;
	while (i < (7 - (int)ft_strlen(test)) && g_booleen == 0)
	{
		g_booleen = 1;
		i++;
		if (kill(pid, SIGUSR1))
		{
			ft_printf("Mauvais PID.\n");
			return (free(test));
		}
		while (g_booleen)
			;
	}
}

void	ft_yacine(int pid, char *str)
{
	char	*test;
	int		result;
	int		j;

	j = 0;
	while (str[j])
	{
		result = 0;
		test = ft_itoa(ft_binaire(str[j], &result));
		if (ft_strlen(test) < 7)
			ft_trop_court(pid, test);
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
