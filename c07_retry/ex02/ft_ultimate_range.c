/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:49:38 by jabae             #+#    #+#             */
/*   Updated: 2021/09/25 17:10:52 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tmp;
	int	i;

	if (min >= max)
	{
		tmp = NULL;
		return (0);
	}
	tmp = malloc(sizeof(int) * (max - min));
	if (tmp == NULL)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		tmp[i] = min + i;
		++i;
	}
	tmp[i] = '\0';
	*range = tmp;
	return (max - min);
}
