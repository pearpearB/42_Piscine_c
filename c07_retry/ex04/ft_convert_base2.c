/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:22:15 by jabae             #+#    #+#             */
/*   Updated: 2021/09/28 23:35:58 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size(int nbr, int base_len, int sign)
{
	int	num;
	int	size;

	num = nbr;
	size = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / base_len;
		size++;
	}
	if (sign < 0)
		return (size + 1);
	else
		return (size);
}

char	*ft_convert_base2(int nbr, char *base_to, int base_len, int sign)
{
	char	*change;
	int		size;
	int		num;

	size = ft_size(nbr, base_len, sign);
	change = malloc(sizeof(char) * size + 1);
	if (change == NULL)
		return (NULL);
	num = nbr;
	change[size] = '\0';
	if (num == 0)
		change[--size] = base_to[num % base_len];
	if (sign < 0 && num != 0)
		change[0] = '-';
	while (num > 0)
	{
		change[--size] = base_to[num % base_len];
		num = num / base_len;
	}
	return (change);
}
