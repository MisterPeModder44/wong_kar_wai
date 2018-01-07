/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_score.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 11:56:50 by mressier          #+#    #+#             */
/*   Updated: 2018/01/07 11:56:51 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "score.h"

static int		internal_set_name_from_string(const char *ptr,
					t_score *new_score, char **s_next)
{
	int		i;

	i = 0;
	while (ptr[i] && ptr[i] != NAME_SEPARATOR_CHAR && i < NAME_SIZE_MAX
			&& t_score_is_valid_char_name(ptr[i]))
	{
		new_score->name[i] = ptr[i];
		i++;
	}
	if (i == 0)
		return (EXIT_FAILURE);
	new_score->name[i] = '\0';
	*s_next = (char *)&(ptr[i]);
	if (ptr[i] != NAME_SEPARATOR_CHAR)
		return (EXIT_FAILURE);
	*s_next = (char *)&(ptr[i + 1]);
	return (EXIT_SUCCESS);
}

static int		internal_set_score_from_string(const char *ptr,
					t_score *new_score, char **s_next)
{
	int		score;
	int		i;

	i = 0;
	while (ptr[i] && ptr[i] != SCORE_SEPARATOR_CHAR)
		i++;
	if (ptr[i] != SCORE_SEPARATOR_CHAR)
		return (EXIT_FAILURE);
	((char *)ptr)[i] = '\0';
	score = ft_atoi(ptr);
	if (score < 0)
		score = 0;
	new_score->score = score;
	*s_next = (char *)&(ptr[i + 1]);
	return (EXIT_SUCCESS);
}

/*
** string format from score:
** Name=score;Name=score;
*/
int				t_score_from_file_string(const char *s, t_score *new_score,
					char **s_next)
{
	char		*ptr;

	ft_bzero(new_score, sizeof(t_score));
	if (internal_set_name_from_string(s, new_score, &ptr) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (internal_set_score_from_string(ptr, new_score, s_next) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
** should be use for register a score
*/
int				t_score_set_name_from_string(const char *name, t_score *score)
{
	char		*next;

	if (internal_set_name_from_string(name, score, &next) == EXIT_FAILURE
			|| *next != '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
