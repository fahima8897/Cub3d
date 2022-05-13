/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:37 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/13 13:27:02 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *av)
{
	int		i;
	char	*format;

	i = 0;
	format = "cub";
	if (av[0] == '.')
		return (-1);
	if (parse(av) == -1)
		return (1);
	while (av[i])
	{
		if (av[i] == '.')
		{
			i++;
			if (ft_strcmp((av + i), format) != 0)
				return (-1);
		}
		i++;
	}
	return (0);
}

void	check_file(char *av)
{
	int	fd;

	fd = open(av, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		printf("Error\nThis is not a file\n");
		exit(0);
	}
	else if (fd < 0)
	{
		close(fd);
		printf("Error\nExtension file missing\n");
		exit(0);
	}
}

void	check_arguments(int ac, char *av)
{
	int	ret;

	ret = 0;
	if (ac != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit(0);
	}
	ret = check_extension(av);
	if (ret == -1)
	{
		printf("Error\nExtension map invalid\n");
		exit(0);
	}
	if (ret == 1)
		check_file(av);
}

int	main(int ac, char **av)
{
	check_arguments(ac, av[1]);
	return (SUCCESS);
}
