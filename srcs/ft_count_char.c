/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:39:23 by mressier          #+#    #+#             */
/*   Updated: 2018/01/07 12:39:23 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** ft_count_char
**
** Give the number of occurence of the character c in the string str
**
** @param		str
** @param		c
**
** @error str is NULL
**
** @return 0 if null or there is no c in str, else the number of occurence of c
*/

int			ft_count_char(const char *str, int c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			n++;
		i++;
	}
	if (c == '\0')
		n++;
	return (n);
}
