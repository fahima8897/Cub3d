/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_content_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:12:05 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/06 20:16:00 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
			return (FAILURE);
		if (reduce_compare_and_check_line_f(split_byspace[1]) == FAILURE)
			return (FAILURE);
	}
	if (strncmp(split_byspace[0], "C", 2) == 0)
	{
		check->c++;
		if (check_verif(*check) == FAILURE)
			return (FAILURE);
		if (reduce_compare_and_check_line_c(split_byspace[1]) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

int	reduce_fonction_above(char **s_byspa, t_verif *check, char *str,
	t_data *data)
{
	if (s_byspa[1])
	{
		if (compare_and_open_line(s_byspa, check, str, data) == -1)
			return (reduce_check_filled_lines(s_byspa));
		if (compare_and_check_number_line(s_byspa, check) == FAILURE)
			return (reduce_check_filled_lines(s_byspa));
	}
	if (s_byspa[2])
		return (ret_free(NULL, s_byspa));
	else
		free_tab(s_byspa);
	return (SUCCESS);
}

int	check_filled_lines(char **map, t_verif *check, t_data *data)
{
	int		i;
	char	**s_byspa;

	i = -1;
	s_byspa = NULL;
	while (map[++i])
	{
		if (check_whitespace(map[i]) == SUCCESS)
		{
			s_byspa = ft_split(map[i], ' ');
			if (!s_byspa[1])
				return (ret_free(NULL, s_byspa));
			if (reduce_fonction_above(s_byspa, check, s_byspa[1], data) == -1)
				return (FAILURE);
		}
		else
			return (FAILURE);
	}
	return (SUCCESS);
}

int	check_line_content(t_map *map, t_data *data)
{
	t_verif	check;

	check = verif_init();
	if (check_filled_lines(map->map, &check, data) == FAILURE)
		return (return_failure("Error\nError Parsing."));
	if (check_verif_2(check) == FAILURE)
		return (return_failure("Error\nError Parsing."));
	return (SUCCESS);
}
