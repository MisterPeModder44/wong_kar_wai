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
#include "game_2048.h"
#include <fcntl.h>
#include <unistd.h>

/*
** string format from score:
** Name=score;Name=score;
*/

static int		internal_get_nb_score_from_file(const char *s)
{
	int		nb_score;

	nb_score = ft_count_char(s, SCORE_SEPARATOR_CHAR);
	if (nb_score > SCORE_DISPLAYED_MAX)
		nb_score = SCORE_DISPLAYED_MAX;
	return (nb_score);
}

static int		internal_set_score_tab_from_string(const char *file_ptr,
					t_score_tab *scores)
{
	char			*next;
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	scores->nb_score = internal_get_nb_score_from_file(file_ptr);
	while (file_ptr && *file_ptr && i < scores->nb_score)
	{
		next = NULL;
		if (t_score_from_file_string(file_ptr,
				&(scores->score_tab[count]), &next) == EXIT_SUCCESS)
			count++;
		else
		{
			scores->nb_score = count;
			break ;
		}
		file_ptr = next;
		i++;
	}
	return (EXIT_SUCCESS);
}

int				t_score_tab_to_file(t_score_tab scores,
					const char *filename)
{
	int					fd;
	unsigned int		i;
	t_score				score;

	i = 0;
	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (EXIT_FAILURE);
	while (i < scores.nb_score)
	{
		score = scores.score_tab[i];
		ft_putstr_fd(score.name, fd);
		ft_putchar_fd(NAME_SEPARATOR_CHAR, fd);
		ft_putnbr_fd(score.score, fd);
		ft_putchar_fd(SCORE_SEPARATOR_CHAR, fd);
		i++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int				t_score_tab_from_file(const char *filename,
					t_score_tab *scores)
{
	char			*ptr_file;

	ptr_file = NULL;
	ft_bzero(scores, sizeof(t_score_tab));
	if (ft_read_file_with_filename(filename, &ptr_file) == EXIT_FAILURE
			|| ptr_file == NULL)
	{
		scores->nb_score = 0;
		return (EXIT_SUCCESS);
	}
	return (internal_set_score_tab_from_string(ptr_file, scores));
}
