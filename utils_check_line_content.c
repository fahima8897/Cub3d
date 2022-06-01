/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_line_content.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:42:39 by fboumell          #+#    #+#             */
/*   Updated: 2022/06/01 18:36:26 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		return (ret_free("Error\nWrong syntax for F.", s_comma));
	if (size_tab != 3)
		return (ret_free("Error\nWrong syntax for F.\n", s_comma));
	while (s_comma[i])
	{
		tmp = strdup_no_n(s_comma[i]);
		if (check_digit(tmp) == FAILURE)
			return (ret_free2("Error\nNon-digit character in F.", s_comma, tmp));
		if (check_digit_size(ft_atoi(tmp)) == FAILURE)
			return (ret_free2("Error\nNumber small or big in F.", s_comma, tmp));
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
		return (ret_free("Error\nWrong syntax for C.", s_comma));
	if (size_tab != 3)
		return (ret_free("Error\nWrong syntax for C.", s_comma));
	while (s_comma[i])
	{
		tmp = strdup_no_n(s_comma[i]);
		if (check_digit(tmp) == FAILURE)
			return (ret_free2("Error\nNon-digit character in C.", s_comma, tmp));
		if (check_digit_size(ft_atoi(tmp)) == FAILURE)
			return (ret_free2("Error\nNumber small or big in C.", s_comma, tmp));
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
