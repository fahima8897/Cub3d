/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:12:05 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/18 17:17:20 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_verif_content(char *str, t_verif *check)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] == 'N' && str[i + 1] == 'O' && (str[i + 2] != ' '
				|| str[i + 2] > '\t'))
		{
			check->no++;
			if (check_verif(*check) == FAILURE)
				return (return_failure("Error\nYou have too much NO."));
		}
		if (str[i] == 'S' && str[i + 1] == 'O' && (str[i + 2] != ' '
				|| str[i + 2] != '\t'))
		{
			check->so++;
			if (check_verif(*check) == FAILURE)
				return (return_failure("Error\nYou have too much SO."));
		}
		if (str[i] == 'W' && str[i + 1] == 'E' && (str[i + 2] != ' '
				|| str[i + 2] != '\t'))
		{
			check->we++;
			if (check_verif(*check) == FAILURE)
				return (return_failure("Error\nYou have too much WE."));
		}
		if (str[i] == 'E' && str[i + 1] == 'A' && (str[i + 2] != ' '
				|| str[i + 2] != '\t'))
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
		i++;
	}
	return (SUCCESS);
}

int	compare_and_open_line(char **split_byspace, t_verif *check, char *tmp)
{
	if (ft_strncmp(split_byspace[0], "NO", 3) == 0)
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

int	compare_and_check_number_line(char **split_byspace, t_verif *check)
{
	if (strncmp(split_byspace[0], "F", 1) == 0)
	{
		check->f++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much F.\n"));
		if (reduce_compare_and_check_line_f(split_byspace[1]) == FAILURE)
			return (FAILURE);
	}
	if (strncmp(split_byspace[0], "C", 1) == 0)
	{
		check->c++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much C."));
		if (reduce_compare_and_check_line_c(split_byspace[1]) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	check_filled_lines(char **map, t_verif *check)
{
	int		i;
	char	**s_byspa;
	char	*tmp;

	i = -1;
	while (map[++i])
	{

		if (ft_strlen(map[i]) > 1)
		{
			if (map[i][0] == '\n')
				i++;
			s_byspa = ft_split(map[i], ' ');
			if (s_byspa[2] && s_byspa[2][0] != '\n')
				return (ret_free("Error\nWrong syntax.", s_byspa));
			if (ft_strncmp(s_byspa[0], "NO", 3) != 0 && ft_strncmp(s_byspa[0], "SO", 3) != 0
				&& ft_strncmp(s_byspa[0], "WE", 3) != 0 && ft_strncmp(s_byspa[0], "EA", 3) != 0
				&& ft_strncmp(s_byspa[0], "F", 2) != 0 && ft_strncmp(s_byspa[0], "C", 2) != 0)
				ret_free("Error\nWrong syntax.LLLL", s_byspa);
			if (s_byspa[1])
			{
				tmp = strdup_no_n(s_byspa[1]);
				if (compare_and_open_line(s_byspa, check, tmp) == FAILURE)
					return (reduce_check_filled_lines(s_byspa, tmp));
				if (compare_and_check_number_line(s_byspa, check) == FAILURE)
					return (reduce_check_filled_lines(s_byspa, tmp));
				free(tmp);
			}
			free_tab(s_byspa);
		}
	}
	return (SUCCESS);
}

int	check_line_content(t_map *map)
{
	t_verif	check;

	check = verif_init();
	if (check_filled_lines(map->map, &check) == FAILURE)
	{
		printf("FAILURE\n"); //printf a garder??
		return (FAILURE);
	}/*
	if (check_verif_2(check) == FAILURE)
	{
		printf("FAILURE verif != 1\n"); //printf a garder??
		return (FAILURE);
	}
	printf("SUCCESS !\n");*/
	return (SUCCESS);
}
