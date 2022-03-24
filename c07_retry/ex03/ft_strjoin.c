/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 20:05:24 by jabae             #+#    #+#             */
/*   Updated: 2021/09/27 19:46:03 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strs_len(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len = len + (ft_strlen(sep) * (size - 1));
	return (len);
}

void	ft_putstrs(char *result, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			result[z] = strs[i][j];
			z++;
			j++;
		}	
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
		{
			result[z] = sep[j];
			z++;
			j++;
		}
		i++;
	}
	result[z] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	 int	total_len;

	total_len = ft_strs_len(size, strs, sep);
	if (size <= 0)
		result = malloc(sizeof(char) * 1);
	else
		result = malloc(sizeof(char) * total_len + 1);
	if (result == NULL)
		return (NULL);
	ft_putstrs(result, size, strs, sep);
	return (result);
}
