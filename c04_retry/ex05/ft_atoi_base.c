/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:00:22 by jabae             #+#    #+#             */
/*   Updated: 2021/09/25 16:41:30 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	change_str_base(char *str, char *base, int base_len, int i)
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
			}
			j++;
		}
		if (base[j] != '\0')
			break ;
		i++;
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	result;
	int	start_index;

	base_len = check_base(base);
	if (base_len != 0)
	{
		start_index = check_str(str);
		if (start_index < 0)
		{
			start_index *= -1;
			result = change_str_base(str, base, base_len, start_index);
			return (result * -1);
		}
		result = change_str_base(str, base, base_len, start_index);
		return (result);
	}
	else
		return (0);
}
