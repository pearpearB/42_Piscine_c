/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:01:12 by jabae             #+#    #+#             */
/*   Updated: 2021/09/25 18:52:16 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	len;
	int	j;

	len = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '+' || base[len] == '-')
			return (0);
		j = len + 1;
		while (base[j] != '\0')
		{
			if (base[j] == base[len])
				return (0);
			++j;
		}
		++len;
	}
	if (len <= 1)
		return (0);
	return (len);
}

void	change_base(int nbr, int base_len, char *base)
{
	if (nbr == 0)
		return ;
	else
	{
		change_base(nbr / base_len, base_len, base);
		write(1, &base[nbr % base_len], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	last;

	base_len = check_base(base);
	if (base_len != 0)
	{
		if (nbr == -2147483648)
		{
			write(1, "-", 1);
			last = (nbr % base_len) * -1;
			nbr = (nbr / base_len) * -1;
			change_base(nbr, base_len, base);
			write(1, &base[last], 1);
		}
		else if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = nbr * -1;
			change_base(nbr, base_len, base);
		}
		else
			change_base(nbr, base_len, base);
	}
	else
		return ;
}
