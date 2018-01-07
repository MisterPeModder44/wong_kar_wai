/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_score_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:23:47 by mressier          #+#    #+#             */
/*   Updated: 2018/01/07 12:23:47 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "score.h"

#define OK_CHAR		"qwertyuiopasdfghjklzxcvbnm"
#define OK_CHAR2	"QWERTYUIOPASDFGHJKLZXCVBNM"
#define OK_CHAR3	"0123456789-_"

bool		t_score_is_valid_char_name(char c)
{
	if (c == '\0')
		return (false);
	if (ft_strchr(OK_CHAR, c)
			|| ft_strchr(OK_CHAR2, c)
			|| ft_strchr(OK_CHAR3, c))
		return (true);
	return (false);
}

bool		t_score_is_valid_name(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && i < NAME_SIZE_MAX)
	{
		if (!t_score_is_valid_char_name(s[i]))
			return (false);
		i++;
	}
	return (true);
}
