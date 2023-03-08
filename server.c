/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:31:57 by ilselbon          #+#    #+#             */
/*   Updated: 2023/03/08 15:22:05 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*ft_strcat(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
	{
		new = malloc(sizeof(char) * 2);
		if (!new)
			return (NULL);
	}
	else
	{
		new = malloc(sizeof(char) * (ft_strlen(str) + 2));
		if (!new)
			return (NULL);
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
		free(str);
	}
	new[i] = c;
	new[i + 1] = 0;
	return (new);
}

char	*ft_chaine_de_charac(char c)
{
	static char	*chaine;

	if (c == 0)
	{
		ft_printf("%s\n", chaine);
		free(chaine);
		chaine = NULL;
	}
	else
		chaine = ft_strcat(chaine, c);
	return (chaine);
}

char	ft_non_binaire(int c, int *result)
{
	if (c == 0 || (c >= 1 && c <= 9))
	{
		if (c == 1)
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

void	ft_test(int ref, siginfo_t *siginfo, void *context)
{
	static char	lettre[8];
	int			pid;
	int			i;
	int			charac;

	(void) context;
	pid = siginfo->si_pid;
	i = 0;
	lettre[7] = 0;
	charac = 0;
	while (lettre[i])
		i++;
	if (ref == SIGUSR1)
		lettre[i] = '0';
	else if (ref == SIGUSR2)
		lettre[i] = '1';
	if (i == 6)
	{
		ft_non_binaire(ft_atoi(lettre), &charac);
		ft_chaine_de_charac(charac);
		i = 0;
		while (i < 7)
			lettre[i++] = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = ft_test;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID : %d\n", getpid());
	while (1)
		;
	return (0);
}
