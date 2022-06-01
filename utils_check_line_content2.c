/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_line_content2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:54:13 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/01 16:54:28 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_no(t_verif *check, char *tmp)
{
	check->no++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nError Parsing."));
	if (open(tmp, O_RDONLY) < 0)
		return (return_failure("Error\nError Parsing."));
	return (SUCCESS);
}

int	check_so(t_verif *check, char *tmp)
{
	check->so++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nError Parsing."));
	if (open(tmp, O_RDONLY) < 0)
		return (return_failure("Error\nError Parsing."));
	return (SUCCESS);
}

int	check_we(t_verif *check, char *tmp)
{
	check->we++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nError Parsing."));
	if (open(tmp, O_RDONLY) < 0)
		return (return_failure("Error\nError Parsing."));
	return (SUCCESS);
}

int	check_ea(t_verif *check, char *tmp)
{
	check->ea++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nError Parsing."));
	if (open(tmp, O_RDONLY) < 0)
		return (return_failure("Error\nError Parsing."));
	return (SUCCESS);
}
