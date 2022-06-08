/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:38:16 by adaloui           #+#    #+#             */
/*   Updated: 2022/06/07 13:51:09 by adaloui          ###   ########.fr       */
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

int	ret_free(char *error_str, char **tab)
{
	if (error_str != NULL)
		printf("\033[1;31m%s\n\033[0m", error_str);
	free_tab(tab);
	return (FAILURE);
}

int	ret_free2(char *error_str, char **tab, char *tmp)
{
	if (error_str != NULL)
		printf("\033[1;31m%s\n\033[0m", error_str);
	free_tab(tab);
	free(tmp);
	return (FAILURE);
}

int	ret_free_txt(char *error_str, char **s_byspace, t_data *data)
{
	printf("\033[1;31m%s\n\033[0m", error_str);
	free_loading_txt_failed(data, s_byspace);
	return (FAILURE);
}
