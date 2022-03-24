/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:09:31 by jabae             #+#    #+#             */
/*   Updated: 2021/09/29 20:11:19 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	flag_asc;
	int	flag_des;

	i = 0;
	flag_asc = 1;
	flag_des = 1;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			flag_asc = 0;
		i++;
	}
	i = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			flag_des = 0;
		i++;
	}
	if (flag_asc == 0 && flag_des == 0)
		return (0);
	return (1);
}
