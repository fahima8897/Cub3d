/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:12:05 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/18 11:33:27 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_check_verif_content(char *str, t_verif *check)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == 'N' && str[i + 1] == 'O' && (str[i + 2] != ' ' || str[i + 2] > '\t'))
		{
			check->no++;
			if (check_verif(*check) == FAILURE)
				return (return_failure("Error\nYou have too much NO."));
		}
		if (str[i] == 'S' && str[i + 1] == 'O' && (str[i + 2] != ' ' || str[i + 2] != '\t'))
		{
			check->so++;
			if (check_verif(*check) == FAILURE)
				return (return_failure("Error\nYou have too much SO."));
		}
		if (str[i] == 'W' && str[i + 1] == 'E' && (str[i + 2] != ' ' || str[i + 2] != '\t'))
		{
			check->we++;
			if (check_verif(*check) == FAILURE)
				return (return_failure("Error\nYou have too much WE."));
		}
		if (str[i] == 'E' && str[i + 1] == 'A' && (str[i + 2] != ' ' || str[i + 2] != '\t'))
		{
			check->ea++;
			if (check_verif(*check) == FAILURE)
				return (return_failure("Error\nYou have too much EA."));
		}
		if (str[i] == 'F' && (str[i + 1] != ' ' || str[i + 1] != '\t'))
		{
			check->f++;
			if (check_verif(*check) == FAILURE)
				return (return_failure("Error\nYou have too much F."));
		}
		if (str[i] == 'F' && (str[i + 1] != ' ' || str[i + 1] != '\t'))
		{
			check->c++;
			if (check_verif(*check) == FAILURE)
				return (return_failure("Error\nYou have too much C."));
		}
		/*else
		{
			printf("i == %d\n", i);
			return (return_failure("Error.\nUnwanted words present in .cub file."));
		}*/
		i++;
	}
	return (SUCCESS);
}

int	ft_compare_and_open_line(char **split_byspace, t_verif *check, char *tmp)
{
	if (ft_strncmp(split_byspace[0], "NO", 2) == 0)
	{
		check->no++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much NO."));
		if (open(tmp, O_RDONLY) < 0)
			return (return_failure("Error\nCould not open file for NO."));
		printf("NO trouve\n");
	}
	if (ft_strncmp(split_byspace[0], "SO", 2) == 0)
	{
		check->so++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much SO."));
		if (open(tmp, O_RDONLY) < 0)
			return (return_failure("Error\nCould not open file for SO."));
		printf("SO trouve\n");
	}
	if (ft_strncmp(split_byspace[0], "WE", 2) == 0)
	{
		check->we++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much WE."));
		if (open(tmp, O_RDONLY) < 0)
			return (return_failure("Error\nCould not open file for WE."));
		printf("WE trouve\n");
	}
	if (ft_strncmp(split_byspace[0], "EA", 2) == 0)
	{
		check->ea++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much EA."));
		if (open(tmp, O_RDONLY) < 0)
			return (return_failure("Error\nCould not open file for EA."));
		printf("EA trouve\n");
	}
	return (SUCCESS);
}



int ft_compare_and_check_number_line(char **split_byspace, t_verif *check)
{
	char	**split_bycomma;
	int		i;
	int		size_tab;
	char	*tmp;

	i = 0;
	if (strncmp(split_byspace[0], "F", 1) == 0)
	{
		check->f++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much F."));
		split_bycomma = ft_split(split_byspace[1], ',');
		size_tab = strlen_tab(split_bycomma);
		if (size_tab != 3)
			return (return_failure("Error\nWrong syntax for F."));
		while (split_bycomma[i])
		{
			tmp = strdup_no_n(split_bycomma[i]);
			printf(" tmp in F == %s", tmp);
			if (check_digit(tmp) == FAILURE)
				return (return_failure("Error\nNon-digit character in F."));
			if (check_digit_size(ft_atoi(tmp)) == FAILURE)
				return (return_failure("Error\nNumber too small or big in F."));
			free(tmp);
			i++;
		}
		free_tab(split_bycomma);
	}
	i = 0;
	if (strncmp(split_byspace[0], "C", 1) == 0)
	{
		check->c++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much C."));
		split_bycomma = ft_split(split_byspace[1], ',');
		size_tab = strlen_tab(split_bycomma);
		if (size_tab != 3)
			return (return_failure("Error\nWrong syntax for C."));
		while (split_bycomma[i])
		{
			tmp = strdup_no_n(split_bycomma[i]);
			printf("tmp in C == %s", tmp);
			if (check_digit(tmp) == FAILURE)
				return (return_failure("Error\nNon-digit character in C."));
			if (check_digit_size(ft_atoi(tmp)) == FAILURE)
				return (return_failure("Error\nNumber too small or big in C."));
			free(tmp);
			i++;
		}
		free_tab(split_bycomma);
	}
	return (SUCCESS);
}

int ft_check_filled_lines(char **map, t_verif *check)
{
	int		i;
	char	**split_byspace;
	char	*tmp;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > 1)
		{
			if (map[i][0] == '\n')
				i++;
			split_byspace = ft_split(map[i], ' ');
/*			if (split_byspace[2] && split_byspace[2][0] != '\n')
			{
				free_tab(split_byspace);
				return (return_failure("Error\nSyntax error."));
			}*/
			if (split_byspace[1])
			{
				tmp = strdup_no_n(split_byspace[1]);
				if (ft_compare_and_open_line(split_byspace,
						check, tmp) == FAILURE)
				{
					free_tab(split_byspace);
					free(tmp);
					return (FAILURE);
				}
				if (ft_compare_and_check_number_line(split_byspace,
						check) == FAILURE)
				{
					free_tab(split_byspace);
					free(tmp);
					return (FAILURE);
				}
				free(tmp);
			}
			free_tab(split_byspace);
		}
		i++;
	}
	return (SUCCESS);
}

int	check_line_content(t_map *map)
{
	t_verif check;

	check = verif_init();
	if (ft_check_filled_lines(map->map, &check) == FAILURE)
	{
		printf("FAILURE\n");
		return (FAILURE);
	}
	// printf ("2 check.c == %lld\n", check.c);
	// printf ("2 check.f == %lld\n", check.f);
	// printf ("2 check.ea == %lld\n", check.ea);
	// printf ("2 check.no == %lld\n", check.no);
	// printf ("2 check.so == %lld\n", check.so);
	// printf ("2 check.we == %lld\n", check.we);
	if (check_verif_2(check) == FAILURE)
	{
		printf("FAILURE verif != 1\n");
		return (FAILURE);
	}
	printf("SUCCESS !\n");
/*	printf ("2 check.c == %lld\n", check.c);
	printf ("2 check.f == %lld\n", check.f);
	printf ("2 check.ea == %lld\n", check.ea);
	printf ("2 check.no == %lld\n", check.no);
	printf ("2 check.so == %lld\n", check.so);
	printf ("2 check.we == %lld\n", check.we);*/
	return (SUCCESS);
}
