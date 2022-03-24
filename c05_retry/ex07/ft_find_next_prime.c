/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:31:37 by jabae             #+#    #+#             */
/*   Updated: 2021/09/25 10:09:35 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	j;

	if (nb <= 1)
		return (0);
	else if (nb > 2 && nb % 2 == 0)
		return (0);
	else
	{
		j = 2;
		while (j <= nb / j)
		{
			if (nb % j == 0)
				return (0);
			++j;
		}
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 2)
		return (2);
	i = nb;
	while (ft_is_prime(i) != 1)
		++i;
	return (i);
}
