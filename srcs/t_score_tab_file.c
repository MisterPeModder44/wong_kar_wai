/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_score_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:17:50 by mressier          #+#    #+#             */
/*   Updated: 2018/01/07 12:17:51 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "score.h"
#include "libft.h"

/*
** string format from score:
** Name=score;Name=score;
*/

static int		internal_get_nb_score_from_file(const char *s)
{
	int		nb_score;

	nb_score = ft_count_char(ptr_file, SCORE_SEPARATOR_CHAR);
	if (nb_score > SCORE_DISPLAYED_MAX)
		nb_score = SCORE_DISPLAYED_MAX;
	return (nb_score);
}

int				t_score_tab_to_file(t_score_tab score_tab, int fd)
{
	int		i;
	t_score	score;

	i = 0;
	if (fd < 0)
		return (EXIT_FAILURE);
	while (i < score_tab.nb_score)
	{
		score = score_tab[i];
		ft_putstr_fd(score.name, fd);
		ft_putchar_fd(NAME_SEPARATOR_CHAR, fd);
		ft_putnbr_fd(score.score, fd);
		ft_putchar_fd(SCORE_SEPARATOR_CHAR, fd);
		i++;
	}
	return (EXIT_SUCCESS);
}

void			t_score_tab_from_file(const char *filename,
					t_score_tab *score_tab)
{
	char		*ptr_file;
	char		*next;
	int			i;
	int			count;

	ft_bzero(score_tab, sizeof(t_score_tab));
	if (ft_read_file_with_filename(filename, &ptr_file) == EXIT_FAILURE)
	{
		score_tab->nb_score = 0;
		return (EXIT_SUCCESS);
	}
	score_tab->nb_score = internal_get_nb_score_from_file(ptr_file);
	i = 0;
	count = 0;
	while (*ptr_file && i < SCORE_DISPLAYED_MAX)
	{
		if (t_score_from_file_string(ptr_file,
				&(score_tab->score_tab[count]), &next) == EXIT_SUCCESS)
			count++;
		ptr_file = next;
		i++;
	}
	return (EXIT_SUCCESS);
}
