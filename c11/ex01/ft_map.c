/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:49:15 by jabae             #+#    #+#             */
/*   Updated: 2021/09/28 18:04:19 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*tmp_tab;
	int	i;

	i = 0;
	tmp_tab = malloc(sizeof(*tab) * length);
	while (i < length)
	{
		tmp_tab[i] = f(tab[i]);
		i++;
	}
	return (tmp_tab);
}
