/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:36:10 by glions            #+#    #+#             */
/*   Updated: 2024/02/23 13:37:48 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_swap_update_size(t_push_swap *ps)
{
	ps->pile_a_s = pile_size(ps->pile_a);
	ps->pile_b_s = pile_size(ps->pile_b);
}