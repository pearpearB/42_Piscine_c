/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:31:04 by jabae             #+#    #+#             */
/*   Updated: 2021/09/25 17:10:52 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*tmp_src;
	 int	i;
	 int	j;	

	i = 0;
	while (src[i] != '\0')
		i++;
	tmp_src = malloc(sizeof(char) * i + 1);
	if (tmp_src == NULL)
		return (NULL);
	j = 0;
	while (src[j] != '\0')
	{
		tmp_src[j] = src[j];
		++j;
	}
	tmp_src[j] = '\0';
	return (tmp_src);
}
