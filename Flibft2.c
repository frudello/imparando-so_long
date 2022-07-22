/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Flibft2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frudello <frudello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:31:51 by frudello          #+#    #+#             */
/*   Updated: 2022/07/02 13:39:38 by frudello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	fcount(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*f;
	long	a;

	i = fcount(n);
	a = n;
	if (a < 0)
	{
		a *= -1;
		i++;
	}
	f = (char *)malloc(i + 1);
	if (!f)
		return (0);
	f[i] = '\0';
	while (i--)
	{
		f[i] = (char)((a % 10) + 48);
		a /= 10;
	}
	if (n < 0)
		f[0] = '-';
	return (f);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar((n + 48));
		return ;
	}
	else
		ft_putnbr(n / 10);
	ft_putnbr(n % 10);
}
