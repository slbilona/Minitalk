/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilselbon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:18:34 by ilselbon          #+#    #+#             */
/*   Updated: 2022/11/18 13:23:39 by ilselbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	lettre;

	lettre = (char) c;
	if (*s == lettre)
		return ((char *) s);
	while (*s++)
	{
		if (*s == lettre)
			return ((char *)s);
	}
	return (NULL);
}
