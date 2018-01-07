/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_score_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 12:58:29 by mressier          #+#    #+#             */
/*   Updated: 2018/01/07 12:58:30 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "score.h"

static void	internal_push_down_scores(t_score_tab *scores, const char *name,
				int score, unsigned int i)
{
	t_score					temp;
	t_score					temp2;

	ft_memcpy(&temp, &(scores->score_tab[i]), sizeof(t_score));
	t_score_set_name_from_string(name, &(scores->score_tab[i]));
	scores->score_tab[i].score = score;
	i++;
	if (scores->nb_score < SCORE_DISPLAYED_MAX)
		scores->nb_score++;
	while (i < scores->nb_score && i < SCORE_DISPLAYED_MAX)
	{
		ft_memcpy(&temp2, &(scores->score_tab[i]), sizeof(t_score));
		ft_memcpy(&(scores->score_tab[i]), &temp, sizeof(t_score));
		temp = temp2;
		i++;
	}
}

int			t_score_add_one(t_score_tab *scores, const char *name,
				int score)
{
	unsigned int			i;

	i = 0;
	if (!t_score_is_valid_name(name) || score < 0)
		return (EXIT_FAILURE);
	while (i < scores->nb_score)
	{
		if (scores->score_tab[i].score < score)
			break ;
		i++;
	}
	if (i < SCORE_DISPLAYED_MAX)
		internal_push_down_scores(scores, name, score, i);
	return (EXIT_SUCCESS);
}
