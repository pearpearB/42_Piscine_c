/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:12:29 by jabae             #+#    #+#             */
/*   Updated: 2021/09/29 13:59:31 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	find_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	strs_count(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (find_sep(*str, charset))
			str++;
		else
		{
			count++;
			while (!find_sep(*str, charset) && *str)
				str++;
		}
	}
	return (count);
}

char	*ft_strdup(char *dest, char *src, char *set)
{
	int	i;
	int	size;

	size = 0;
	while (!find_sep(src[size], set) && src[size])
		size++;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		index;
	int		word_count;

	word_count = strs_count(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result || !str)
		return (NULL);
	index = 0;
	while (*str)
	{
		if (!find_sep(*str, charset))
		{
			result[index] = ft_strdup(result[index], str, charset);
			while (!find_sep(*str, charset) && *str)
				str++;
			index++;
		}
		else
			str++;
	}
	result[index] = 0;
	return (result);
}
