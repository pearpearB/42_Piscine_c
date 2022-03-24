/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:43:31 by jabae             #+#    #+#             */
/*   Updated: 2021/09/25 10:29:02 by jabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] == str2[i])
			i++;
		else
			return (str1[i] - str2[i]);
	}
	if (str2[i] != '\0')
		return (str1[i] - str2[i]);
	return (0);
}

void	ft_print(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			++j;
		}
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	char	*buf;
	 int	i;
	 int	j;

	i = 0;
	if (argc > 1)
	{
		while (++i < argc)
		{
			j = i;
			while (++j < argc)
			{
				if (ft_strcmp(argv[i], argv[j]) > 0)
				{
					buf = argv[i];
					argv[i] = argv[j];
					argv[j] = buf;
				}
			}
		}
		ft_print(argc, argv);
	}
	return (0);
}
