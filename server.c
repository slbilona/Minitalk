#include "server.h"

char lettre[8];

int	ft_lstsize(chaine *lst)
{
	chaine	*actuel;
	int		i;

	actuel = lst;
	if (actuel)
		i = 1;
	else
		return (0);
	while (actuel->next)
	{
		actuel = actuel->next;
		i++;
	}
	return (i);
}

void ft_chaine_de_charac(chaine **list)
{
	chaine *actuel;
	char *new;
	int i;

	i = 0;
	actuel = *list;
	new = malloc(sizeof(char) * (ft_lstsize(*list) + 1));
	while(actuel)
	{
		new[i] = actuel->c;
		i++;
	}
	new[i] = 0;
	printf("%s\n", new);
	free(new);
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
		if(charac == 0)
		{
			ft_chaine_de_charac(list);
		}
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