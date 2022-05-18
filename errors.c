/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:38:16 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/17 11:44:49 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_errors(char *error_str)
{
	printf("\033[1;31m%s\n\033[0m", error_str);
	exit(1);
}

int	return_failure(char *error_str)
{
	printf("\033[1;31m%s\n\033[0m", error_str);
	return (FAILURE);
}