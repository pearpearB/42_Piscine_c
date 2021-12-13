/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:12:12 by jabae             #+#    #+#             */
/*   Updated: 2021/09/18 16:16:20 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_str(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	Up_str(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	Dow_str(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (check_str(str[i]) == 1)
		{
			if ((flag == 1) && (Dow_str(str[i]) == 1))
			{
				str[i] = str[i] - 'a' + 'A';
				flag = 0;
			}
			else if ((flag == 0) && (Up_str(str[i]) == 1))
				str[i] = str[i] - 'A' + 'a';
			else
				flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	return (str);
}
