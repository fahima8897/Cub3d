/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:12:05 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/18 21:02:46 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	compare_and_open_line(char **split_byspace, t_verif *check, char *tmp)
{
	if (ft_strncmp(split_byspace[0], "NO", 3) == 0)
	{
		if (check_no(check, tmp) == FAILURE)
			return (FAILURE);
	}
	if (ft_strncmp(split_byspace[0], "SO", 2) == 0)
	{
		if (check_so(check, tmp) == FAILURE)
			return (FAILURE);
	}
	if (ft_strncmp(split_byspace[0], "WE", 2) == 0)
	{
		if (check_we(check, tmp) == FAILURE)
			return (FAILURE);
	}
	if (ft_strncmp(split_byspace[0], "EA", 2) == 0)
	{
		if (check_ea(check, tmp) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	compare_and_check_number_line(char **split_byspace, t_verif *check)
{
	if (strncmp(split_byspace[0], "F", 1) == 0)
	{
		check->f++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much F."));
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
		s_byspa = ft_split(map[i], ' ');
		if (s_byspa[1])
		{
			tmp = strdup_no_n(s_byspa[1]);
			if (compare_and_open_line(s_byspa, check, tmp) == FAILURE)
				return (reduce_check_filled_lines(s_byspa, tmp));
			if (compare_and_check_number_line(s_byspa, check) == FAILURE)
				return (reduce_check_filled_lines(s_byspa, tmp));
			free(tmp);
		}
		if (s_byspa[2] && s_byspa[2][0] != '\n')
			ret_free("Error\nWrong syntax. Too much words", s_byspa);
		else
			free_tab(s_byspa);
	}
	return (SUCCESS);
}

int	check_line_content(t_map *map)
{
	t_verif	check;

	check = verif_init();
	if (check_filled_lines(map->map, &check) == FAILURE)
		return (return_failure("Error\nProblem in line."));
	if (check_verif_2(check) == FAILURE)
		return (return_failure("Error\nRessources not present."));
	return (SUCCESS);
}
