/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:51:47 by glions            #+#    #+#             */
/*   Updated: 2024/02/22 19:04:24 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	verif_limit(char *str, int size, char *limit)
{
	int	size_max;
	int	i;

	size_max = ft_strlen(limit);
	if (size > size_max)
		return (0);
	if (size < size_max)
		return (1);
	i = 0;
	while (str[i] && i < size)
	{
		if (str[i] > limit[i])
			return (0);
		i++;
	}
	return (1);
}

static int	verif_number(char *str, int size)
{
	int	i;

	i = 0;
	if (size == 0)
		return (0);
	if (str[0] != '-' && !verif_limit(str, size, "2147483647"))
		return (0);
	if (str[0] == '-' && !verif_limit(str, size, "-2147483648"))
		return (0);
	while (str[i] && i < size)
	{
		if (str[i] == '-' && i > 0)
			return (0);
		else if ((str[i] != '-' && i == 0) && (str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	get_next(char *str, int *i, int *nb)
{
	int	j;

	j = 0;
	while (str[j] && (str[j] != ' ' && str[j] != '\t'))
		j++;
	if (verif_number(str, j))
	{
		*i += j;
		*nb = ft_atoin(str, j);
	}
	else
		return (0);
	return (1);
}

t_pile	*parsing_1(int ac, char **av)
{
	t_pile	*pile;
	t_pile	*new;
	int		i;

	i = 1;
	pile = NULL;
	while (i < ac)
	{
		if (verif_number(av[i], ft_strlen(av[i])))
		{
			new = pile_new(ft_atoi(av[i]), 'a');
			if (!new)
				return (printf("error malloc new\n"), pile_free(pile), NULL);
			if (!pile_addback(&pile, new))
				return (printf("error addback\n"), free(new), pile_free(pile),
					NULL);
		}
		else
			return (printf("error verif number\n"), pile_free(pile), (NULL));
		i++;
	}
	return (pile);
}

t_pile	*parsing_2(char *str)
{
	t_pile	*pile;
	t_pile	*new;
	int		i;
	int		nb;

	i = 0;
	pile = NULL;
	while (str[i] && i < (int)ft_strlen(str))
	{
		if (str[i] != ' ' || str[i] != '\t')
		{
			if (get_next(str + i, &i, &nb))
			{
				new = pile_new(nb, 'a');
				if (!new)
					return (pile_free(pile), (NULL));
				if (!pile_addback(&pile, new))
					return (free(new), pile_free(pile), NULL);
			}
			else
				return (pile_free(pile), (NULL));
		}
		i++;
	}
	return (pile);
}
