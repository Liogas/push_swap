/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:14:55 by glions            #+#    #+#             */
/*   Updated: 2024/02/19 12:59:00 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef struct s_pile
{
	int				value;
	struct s_pile	*next;
	struct s_pile	*before;
}	t_pile;

typedef struct s_push_swap
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	int		nb_ins;
}	t_push_swap;

t_pile		*pile_new(int nb);
int			pile_addback(t_pile **pile, t_pile *new);
t_pile		*parsing_1(int ac, char **av);
t_pile		*parsing_2(char *str);
void		pile_free(t_pile *pile);
void		pile_show(t_pile *pile);
void		print_error(void);
void		push_swap_free(t_push_swap *ps);
t_push_swap	*push_swap_new(void);

#endif