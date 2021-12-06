/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:03:53 by jabae             #+#    #+#             */
/*   Updated: 2021/09/13 19:50:16 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	out_combn(char *arr, int n, int i)
{
	if (i == 0)
		arr[i] = '0';
	else
		arr[i] = arr[i - 1] + 1;
	while (arr[i] <= 10 - n + i + '0')
	{
		if (i == n - 1)
		{
			write(1, arr, n);
			if (!(arr[0] == 10 - n + '0'))
				write(1, ", ", 2);
		}
		else
			out_combn(arr, n, i + 1);
		arr[i]++;
	}
}

void	ft_print_combn(int n)
{
	char	arr[9];

	out_combn(arr, n, 0);
}
