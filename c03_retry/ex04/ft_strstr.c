/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 23:41:09 by jabae             #+#    #+#             */
/*   Updated: 2021/09/22 12:19:06 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_po;
	char	*find_po;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		str_po = str;
		find_po = to_find;
		while (*find_po != '\0' && *str_po == *find_po)
		{
			str_po++;
			find_po++;
		}
		if (*find_po == '\0')
			return (str);
		else
			str++;
	}
	return (0);
}
