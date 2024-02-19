/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:40:57 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:47:35 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	cw;
	int	nw;

	i = 0;
	cw = 0;
	nw = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && nw == 1)
		{
			cw++;
			nw = 0;
		}
		else if (s[i] == c)
			nw = 1;
		i++;
	}
	return (cw);
}

static int	ft_wlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*ft_get_word(char const *s, char c, int p)
{
	char	*m;
	int		i;
	int		j;
	int		nw;

	i = -1;
	j = -1;
	nw = 1;
	while (s[++i] != '\0')
	{
		if (s[i] != c && nw == 1)
		{
			if (++j == p)
			{
				m = (char *)malloc((ft_wlen(s + i, c) + 1) * sizeof(char));
				if (!m)
					return (NULL);
				return (ft_strlcpy(m, s + i, ft_wlen(s + i, c) + 1), (m));
			}
			nw = 0;
		}
		else if (s[i] == c && nw == 0)
			nw = 1;
	}
	return (NULL);
}

static void	ft_free(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}

char	**ft_split(char const *s, char c)
{
	int		nb_w;
	char	**m;
	int		i;

	if (!s)
		return (NULL);
	nb_w = ft_count_words(s, c);
	m = (char **)malloc((nb_w + 1) * sizeof(char *));
	if (!m)
		return (NULL);
	i = 0;
	while (i < nb_w)
	{
		m[i] = ft_get_word(s, c, i);
		if (!m[i])
		{
			ft_free(m);
			return (NULL);
		}
		i++;
	}
	m[i] = 0;
	return (m);
}
