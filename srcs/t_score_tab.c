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

int			t_score_add_one(t_score_tab *score_tab, const char *name, int score)
{
	unsigned int			i;

	i = 0;
	if (!t_score_is_valid_name(name) || score < 0)
		return (EXIT_FAILURE);
	if (score_tab->nb_score < SCORE_DISPLAYED_MAX)
		score_tab->nb_score++;
	while (i < score_tab->nb_score)
		i++;
	t_score_set_name_from_string(name, &(score_tab->score_tab[i]));
	score_tab->score_tab[i].score = score;
	return (EXIT_SUCCESS);
}

#include <stdio.h>
void		t_score_tab_display(t_score_tab scores)
{
	unsigned int		i;

	i = 0;
	fprintf(stderr, "%s\n", "SCORES:");
	while (i < scores.nb_score)
	{
		fprintf(stderr, "[%d] : {%s} - %d pts\n", i,
			scores.score_tab[i].name, scores.score_tab[i].score);
		i++;
	}
}
