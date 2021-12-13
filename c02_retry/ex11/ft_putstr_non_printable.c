/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:20:47 by jabae             #+#    #+#             */
/*   Updated: 2021/09/18 19:31:13 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	change(int c)
{
	if (c < 10)
		return (c + '0');
	else
		return ((c - 10) + 'a');
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	int		aa;
	int		bb;
	char	after[2];

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32) || (str[i] > 126))
		{
			aa = (unsigned char)str[i] / 16;
			bb = (unsigned char)str[i] % 16;
			after[0] = change(aa);
			after[1] = change(bb);
			write(1, "\\", 1);
			write(1, &after[0], 1);
			write(1, &after[1], 1);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}
