/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:38:16 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/16 19:37:03 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_errors(char *error_str)
{
	printf("\033[1;31m%s\n\033[0m", error_str);
	exit(1);
}

int		return_failure(char *error_str)
{
	printf("\033[1;31m%s\n\033[0m", error_str);
	return(FAILURE);
}