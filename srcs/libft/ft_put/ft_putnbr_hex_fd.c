/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:50:45 by glions            #+#    #+#             */
/*   Updated: 2024/01/19 23:46:59 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_hex_fd(long long n, int fd, int upper)
{
	long long	tmp;

	if (n == 0)
		return ;
	tmp = n % 16;
	ft_putnbr_hex_fd(n / 16, fd, upper);
	if (tmp < 10)
		ft_putchar_fd(tmp + '0', fd);
	else if (upper)
		ft_putchar_fd(tmp + 55, fd);
	else
		ft_putchar_fd(tmp + 87, fd);
}
