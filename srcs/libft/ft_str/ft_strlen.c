/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:04:16 by glions            #+#    #+#             */
/*   Updated: 2024/03/26 13:33:07 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	ft_strlen_skip_c(char c, char *str)
{
	int	i;
	int	j;

	if (str[0] == c && ft_strlen(str) == 1)
		return (1);
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	j = 0;
	while (str[i + j])
		j++;
	return (j);
}
