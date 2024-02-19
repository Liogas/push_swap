/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_constr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:45:24 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:47:33 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_constr(const char *str, const char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}
