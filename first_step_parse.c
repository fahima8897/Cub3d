/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:28:34 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/31 19:37:20 by adaloui          ###   ########.fr       */
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

int	check_arguments(int ac, char *av)
{
	int	ret;

	ret = 0;
	if (ac != 2)
		return (return_failure("Error.\nWrong number of arguments."));
	ret = check_directory(av);
	if (ret == FAILURE)
		return (return_failure("Error.\nYou are trying to open a directory."));
	ret = check_file_existence(av);
	if (ret == FAILURE)
		return (return_failure("Error.\nThe file does not exist."));
	ret = check_extension(av);
	if (ret == FAILURE)
		return (return_failure("Error.\nExtension map invalid."));
	if (ret == 1)
		return (return_failure("Error.\nExtension file missing."));
	return (SUCCESS);
}
