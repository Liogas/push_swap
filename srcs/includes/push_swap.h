/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:55 by glions            #+#    #+#             */
/*   Updated: 2024/02/19 16:26:33 by glions           ###   ########.fr       */
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
	struct s_pile	*before;
}					t_pile;

typedef struct s_push_swap
{
	t_pile			*pile_a;
	t_pile			*pile_b;
	int				nb_ins;
}					t_push_swap;

t_pile				*parsing_1(int ac, char **av);
t_pile				*parsing_2(char *str);

t_pile				*pile_new(int nb);
int					pile_addback(t_pile **pile, t_pile *new);
void				pile_free(t_pile *pile);
void				pile_show(t_pile *pile);
int					pile_size(t_pile *p);

void				print_error(void);

void				push_swap_free(t_push_swap *ps);
t_push_swap			*push_swap_new(void);

void				swap_a(t_pile **p, int show);
void				swap_b(t_pile **p, int show);

void				push_a(t_pile **pa, t_pile **pb, int show);
void				push_b(t_pile **pb, t_pile **pa, int show);

void				rotate_a(t_pile **pa, int show);
void				rotate_b(t_pile **pb, int show);
void				rotate_rr(t_pile **pa, t_pile **pb, int show);

void				reverse_rotate_a(t_pile **pa, int show);
void				reverse_rotate_b(t_pile **pb, int show);
void				reverse_rotate_rrr(t_pile **pa, t_pile **pb, int show);

int					test(t_push_swap *ps);

#endif