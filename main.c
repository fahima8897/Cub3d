/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:37 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/16 19:38:37 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(char *av)
{
	int		i;
	char	*format;

	i = 0;
	format = "cub";
	if (av[5] == '.' || av[0] == '.')
		return (FAILURE);
	if (parse(av) == FAILURE)
		return (1);
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

int	check_directory(char *av)
{
	int	fd;

	fd = open(av, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	check_file_existence(char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

void	check_arguments(int ac, char *av)
{
	int	ret;

	ret = 0;
	if (ac != 2)
		write_errors("Error.\nWrong number of arguments.");
	ret = check_directory(av);
	if (ret == FAILURE)
		write_errors("Error.\nYou are trying to open a directory.");
	ret = check_file_existence(av);
	if (ret == FAILURE)
		write_errors("Error.\nThe file you are trying to open does not exist.");
	ret = check_extension(av);
	if (ret == FAILURE)
		write_errors("Error.\nExtension map invalid.");
	if (ret == 1)
		write_errors("Error.\nExtension file missing.");
}

int	main(int ac, char **av)
{
	t_data	data;

	check_arguments(ac, av[1]);
	if (check_opt_argv_map(av[1]) == FAILURE)
	 	return (FAILURE);
	init_window(&data);
	loop(data);
	return (SUCCESS);
}
