/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:40:37 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/18 23:21:31 by adaloui          ###   ########.fr       */
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
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (FAILURE);
//	printf("Salam Fahima\nJ'ai regle pas mal de truc.\nJe pense avoir termine le parsing pour les ressources\nToutefois, il reste 1 leaks dont je n'arrive pas a me debrarasser (pour les ressources) qui est lie au get next line de count_line, celui qui est ligne 56\n");
//	printf("J'ai pas verifie les leaks pour la map, mais j'ai bien avance sur son paring egalement.\nJe voudrais, pendant le temps ou je suis pas la que tu essayes de trouver le leaks qui est lie a get next line stp, c'est un petit non reachable de qlq bits\n");
	check_arguments(ac, av[1]);
	init_data(data);
	if (check_opt_argv_map(av[1], data) == FAILURE)
	{
		free_data(data);
		return (FAILURE);
	}
	init_window(data);
	loop(data);
	return (SUCCESS);
}
