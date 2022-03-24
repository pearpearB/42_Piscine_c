/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:37:31 by jabae             #+#    #+#             */
/*   Updated: 2021/09/28 23:45:23 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_sep(char c, char *seps)
{
	int	i;

	i = 0;
	while (seps[i] != '\0')
	{
		if (c == seps[i])
			return (1);
		i++;
	}
	return (0);
}

int	strs_count(char *strs, char *seps)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (strs[i] != '\0')
	{
		if (check_sep(strs[i], seps) == 1)
			i++;
		else
		{
			count++;
			while (check_sep(strs[i], seps) == 0)
				i++;
		}
	}
	return (count);
}

char	*ft_strcpy(char *word, char *strs, int index, char *seps)
{
	int	i;

	i = 0;
	while (check_sep(strs[index + i], seps) == 0 && strs[index + i] != '\0')
	{
		word[i] = strs[index + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_seperator(char **result, char *strs, char *seps, int count)
{
	int	i;
	int	w_len;
	int	word_i;

	i = 0;
	word_i = 0;
	while (word_i < count && strs[i] != '\0')
	{
		if (check_sep(strs[i], seps) == 1)
			i++;
		else
		{
			w_len = 0;
			while (check_sep(strs[i + w_len], seps) == 0)
				w_len++;
			result[word_i] = malloc(sizeof(char) * w_len + 1);
			result[word_i] = ft_strcpy(result[word_i], strs, i, seps);
			i = i + w_len;
			word_i++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		count;

	count = strs_count(str, charset);
	result = malloc(sizeof(char *) * (count + 1));
	if (result == NULL || str == NULL)
		return (NULL);
	ft_seperator(result, str, charset, count);
	result[count] = NULL;
	return (result);
}
