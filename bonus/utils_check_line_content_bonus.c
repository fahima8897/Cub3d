/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_line_content_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:42:39 by fboumell          #+#    #+#             */
/*   Updated: 2022/06/03 14:57:55 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	reduce_check_filled_lines(char **split_byspace)
{
	free_tab(split_byspace);
	return (FAILURE);
}

int	reduce_compare_and_check_line_f(char *split_byspace)
{
	char	**s_comma;
	int		i;
	int		size_tab;
	char	*tmp;

	i = 0;
	s_comma = ft_split(split_byspace, ',');
	size_tab = strlen_tab(s_comma);
	if (size_tab == 3 && s_comma[2][0] == '\n')
		return (ret_free("Error\nError Parsing.", s_comma));
	if (size_tab != 3)
		return (ret_free("Error\nError Parsing.", s_comma));
	while (s_comma[i])
	{
		tmp = strdup_no_n(s_comma[i]);
		if (check_digit(tmp) == FAILURE)
			return (ret_free2("Error\nError Parsing.", s_comma, tmp));
		if (check_digit_size(ft_atoi(tmp)) == FAILURE)
			return (ret_free2("Error\nError Parsing.", s_comma, tmp));
		free(tmp);
		i++;
	}
	free_tab(s_comma);
	return (SUCCESS);
}

int	reduce_compare_and_check_line_c(char *split_byspace)
{
	char	**s_comma;
	int		i;
	int		size_tab;
	char	*tmp;

	i = 0;
	s_comma = ft_split(split_byspace, ',');
	size_tab = strlen_tab(s_comma);
	if (size_tab == 3 && s_comma[2][0] == '\n')
		return (ret_free("Error\nError Parsing.", s_comma));
	if (size_tab != 3)
		return (ret_free("Error\nError Parsing.", s_comma));
	while (s_comma[i])
	{
		tmp = strdup_no_n(s_comma[i]);
		if (check_digit(tmp) == FAILURE)
			return (ret_free2("Error\nError Parsing.", s_comma, tmp));
		if (check_digit_size(ft_atoi(tmp)) == FAILURE)
			return (ret_free2("Error\nError Parsing.", s_comma, tmp));
		free(tmp);
		i++;
	}
	free_tab(s_comma);
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
