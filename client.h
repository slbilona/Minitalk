/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <ilselbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:42:09 by ilselbon          #+#    #+#             */
/*   Updated: 2023/03/08 16:24:00 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>
# include "./Ma_Libft/libft.h"

int		ft_atoi(const char *nptr);
int		ft_binaire(int c, int *result);
int		ft_plus_de_place(char *test, int pid);
void	ft_principale(int ref);
void	ft_yacine(int pid, char *str);
void	ft_trop_court(int pid, char *test);
void	ft_fin(int pid);

#endif