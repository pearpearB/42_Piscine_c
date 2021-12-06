/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:20:59 by jabae             #+#    #+#             */
/*   Updated: 2021/09/20 18:04:00 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_outarr(int nb, int i)
{
	char	arr[11];

	i = 0;
	while (i < 11)
	{
		arr[i] = nb % 10 + '0';
		nb /= 10;
		i++;
		if (nb / 10 == 0)
		{
			arr[i] = nb % 10 + '0';
			break ;
		}
	}
	while (i >= 0)
	{
		write(1, &arr[i], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
		ft_outarr(nb, 0);
	}
	else
	{
		ft_outarr(nb, 0);
	}
}
