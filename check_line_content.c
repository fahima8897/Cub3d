/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:12:05 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/01 17:08:22 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	compare_and_open_line(char **split_byspace, t_verif *check, char *tmp,
	t_data *data)
{
	if (ft_strncmp(split_byspace[0], "NO", 3) == 0)
	{
		if (check_no(check, tmp, data) == FAILURE)
			return (FAILURE);
	}
	if (ft_strncmp(split_byspace[0], "SO", 3) == 0)
	{
		if (check_so(check, tmp, data) == FAILURE)
			return (FAILURE);
	}
	if (ft_strncmp(split_byspace[0], "WE", 3) == 0)
	{
		if (check_we(check, tmp, data) == FAILURE)
			return (FAILURE);
	}
	if (ft_strncmp(split_byspace[0], "EA", 3) == 0)
	{
		if (check_ea(check, tmp, data) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	compare_and_check_number_line(char **split_byspace, t_verif *check)
{
	if (strncmp(split_byspace[0], "F", 2) == 0)
	{
		check->f++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much F."));
		if (reduce_compare_and_check_line_f(split_byspace[1]) == FAILURE)
			return (FAILURE);
	}
	if (strncmp(split_byspace[0], "C", 2) == 0)
	{
		check->c++;
		if (check_verif(*check) == FAILURE)
			return (return_failure("Error\nYou have too much C."));
		if (reduce_compare_and_check_line_c(split_byspace[1]) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	check_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] <= 32)
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

int	check_filled_lines(char **map, t_verif *check, t_data *data)
{
	int		i;
	char	**s_byspa;

	i = -1;
	while (map[++i])
	{
		if (check_whitespace(map[i]) == SUCCESS)
		{
			s_byspa = ft_split(map[i], ' ');
			if (!s_byspa[1])
				return (ret_free("Error\nWrong syntax.", s_byspa));
			if (s_byspa[1])
			{
				if (compare_and_open_line(s_byspa, check, s_byspa[1], data) == -1)
					return (reduce_check_filled_lines(s_byspa));
				if (compare_and_check_number_line(s_byspa, check) == FAILURE)
					return (reduce_check_filled_lines(s_byspa));
			}
			if (s_byspa[2])
				return (ret_free("Error\nToo much words", s_byspa));
			else
				free_tab(s_byspa);
		}
		else
			return (return_failure("Error\nCharacter without space"));
	}
	return (SUCCESS);
}

int	check_line_content(t_map *map, t_data *data)
{
	t_verif	check;

	check = verif_init();
	if (check_filled_lines(map->map, &check, data) == FAILURE)
		return (return_failure("Error\nProblem in line."));
	if (check_verif_2(check) == FAILURE)
		return (return_failure("Error\nAt least one ressource is not present."));
	return (SUCCESS);
}
