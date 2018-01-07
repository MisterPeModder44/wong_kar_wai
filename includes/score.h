/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mressier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 11:57:11 by mressier          #+#    #+#             */
/*   Updated: 2018/01/07 11:57:12 by mressier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCORE_H
# define SCORE_H

# include <stdbool.h>
# include <stdio.h>

/*
** string format from score:
** Name=score
** Name=score
** ...
*/

# define SCORE_FILE "scores.txt"

# define SCORE_DISPLAYED_MAX 10

# define NAME_SIZE_MAX 10

# define NAME_SEPARATOR_CHAR	'='
# define SCORE_SEPARATOR_CHAR	'\n'

typedef struct		s_score
{
	char			name[NAME_SIZE_MAX + 1];
	int				score;
}					t_score;

typedef struct		s_score_tab
{
	t_score			score_tab[SCORE_DISPLAYED_MAX];
	unsigned int	nb_score;
}					t_score_tab;

/*
** t_score_tab.c
*/
int					t_score_add_one(t_score_tab *score_tab,
						const char *name, int score);

/*
** t_score_tab_file.c
*/
int					t_score_tab_to_file(t_score_tab score_tab,
						const char *filename);
int					t_score_tab_from_file(const char *filename,
						t_score_tab *scores);

/*
** t_score_from_string.c
*/
int					t_score_from_file_string(const char *s, t_score *new_score,
						char **s_next);
int					t_score_set_name_from_string(const char *name,
						t_score *score);

/*
** t_score_tools.c
*/
bool				t_score_is_valid_name(const char *s);
bool				t_score_is_valid_char_name(char c);

#endif
