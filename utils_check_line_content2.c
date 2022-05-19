/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_check_line_content2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:54:13 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/19 12:04:02 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_no(t_verif *check, char *tmp)
{
	check->no++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nYou have too much NO."));
	if (open(tmp, O_RDONLY) < 0)
		return (return_failure("Error\nCould not open file for NO."));
	//printf("NO trouve\n");
	return (SUCCESS);
}

int	check_so(t_verif *check, char *tmp)
{
	check->so++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nYou have too much SO."));
	if (open(tmp, O_RDONLY) < 0)
		return (return_failure("Error\nCould not open file for SO."));
	//printf("SO trouve\n");
	return (SUCCESS);
}

int	check_we(t_verif *check, char *tmp)
{
	check->we++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nYou have too much WE."));
	if (open(tmp, O_RDONLY) < 0)
		return (return_failure("Error\nCould not open file for WE."));
	//printf("WE trouve\n");
	return (SUCCESS);
}

int	check_ea(t_verif *check, char *tmp)
{
	check->ea++;
	if (check_verif(*check) == FAILURE)
		return (return_failure("Error\nYou have too much EA."));
	if (open(tmp, O_RDONLY) < 0)
		return (return_failure("Error\nCould not open file for EA."));
	//printf("EA trouve\n");
	return (SUCCESS);
}
