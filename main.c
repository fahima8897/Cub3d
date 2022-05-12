/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:37 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/12 17:32:46 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	parse(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '.')
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int	check_format_map(char *av)
{
	int		i;
	char	*format;

	i = 0;
	format = "cub";
	if (parse(av) == FAILURE)
		return (FAILURE);
	while (av[i])
	{
		if (av[i] == '.')
		{
			i++;
			if (ft_strcmp((av + i), format) != 0)
				return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		printf("Wrong number of arguments\n");
		exit(SUCCESS);
	}
	if (check_format_map(av[1]) == FAILURE)
	{
		printf("Format map invalid\n");
		exit(0);
	}
	return (SUCCESS);
}
