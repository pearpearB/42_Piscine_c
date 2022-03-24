/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:59:18 by jabae             #+#    #+#             */
/*   Updated: 2021/09/28 23:36:46 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_size(int nbr, int base_len, int sign);
char	*ft_convert_base2(int nbr, char *base_to, int base_len, int sign);

int	check_base(char *base)
{
	int	len;
	int	j;

	len = 0;
	while (base[len] != '\0')
	{
		if (base[len] == '+' || base[len] == '-'
			|| (base[len] >= 9 && base[len] <= 13) || base[len] == ' ')
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

int	check_str(char *str)
{
	int	i;
	int	sign;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	return (i * sign);
}

int	change_base_from(char *str, char *base, int base_len, int i)
{
	int	j;
	int	number;

	number = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
			{
				number = (number * base_len) + j;
				break ;
			}
			j++;
		}
		if (base[j] == '\0')
			break ;
		i++;
	}
	return (number);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	 int	from_len;
	 int	to_len;
	 int	index;
	 int	decimal;

	from_len = check_base(base_from);
	to_len = check_base(base_to);
	if (from_len != 0 && to_len != 0 && nbr != 0)
	{
		index = check_str(nbr);
		if (index < 0)
		{
			decimal = change_base_from(nbr, base_from, from_len, -index);
			result = ft_convert_base2(decimal, base_to, to_len, -1);
		}
		else
		{
			decimal = change_base_from(nbr, base_from, from_len, index);
			result = ft_convert_base2(decimal, base_to, to_len, 1);
		}
		return (result);
	}
	else
		return (NULL);
}
