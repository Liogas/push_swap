/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:55 by glions            #+#    #+#             */
/*   Updated: 2024/02/28 16:00:33 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int				value;
	struct s_pile	*next;
	char			id_pile;
}					t_pile;

typedef struct s_push_swap
{
	t_pile			*pile_a;
	t_pile			*pile_b;
	int				pile_a_s;
	int				pile_b_s;
	int				nb_ins;
}					t_push_swap;

t_pile				*parsing_1(int ac, char **av);
t_pile				*parsing_2(char *str);

t_pile				*pile_new(int nb, char id);
int					pile_addback(t_pile **pile, t_pile *new);
void				pile_free(t_pile *pile);
void				pile_show(t_pile *pile);
int					pile_size(t_pile *p);
int					pile_issort(t_pile *p, int *exp);
t_pile				*pile_dup(t_pile *p);
int					pile_getpos(int target, t_pile *p);

void				print_error(void);

void				push_swap_free(t_push_swap *ps);
t_push_swap			*push_swap_new(void);
void				push_swap_update_size(t_push_swap *ps);

void				ins_s(t_pile **p, int show);
void				ins_s_all(t_pile **p1, t_pile **p2, int show);

void				ps_ins_p(t_push_swap *ps, int show, int mode);
void				ins_p(t_pile **p_src, t_pile **p_dest, int show);

void				ins_r(t_pile **p, int show);
void				ins_r_all(t_pile **p1, t_pile **p2, int show);

void				ins_rr(t_pile **p, int show);
void				ins_rr_all(t_pile **p1, t_pile **p2, int show);

void				sort_show(int *tab, int size);
int					*sort_list(t_pile *p);

int 				small_algo_ps(t_push_swap *ps, int *exp);
int					big_algo(t_push_swap *ps);

// int					get_target_b(int value, t_pile *p);
// int					get_target_a(int value, t_pile *p);


#endif