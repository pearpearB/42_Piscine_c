/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:33:36 by jabae             #+#    #+#             */
/*   Updated: 2021/09/22 17:12:24 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_outarr(int num_1, int i)
{
	char	arr[10];

	while (num_1 > 0)
	{
		arr[i] = num_1 % 10 + '0';
		num_1 /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(arr[i]);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		ft_putchar('0');
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_outarr(nb * -1, 0);
	}
	else
		ft_outarr(nb, 0);
}
