/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_verif_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:30:02 by fboumell          #+#    #+#             */
/*   Updated: 2022/06/01 20:28:17 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_verif	verif_init(void)
{
	t_verif	check;

	check.c = 0;
	check.f = 0;
	check.ea = 0;
	check.no = 0;
	check.so = 0;
	check.we = 0;
	return (check);
}

int	check_verif(t_verif tab)
{
	if (tab.c > 1 || tab.f > 1)
		return (FAILURE);
	if (tab.ea > 1 || tab.no > 1)
		return (FAILURE);
	if (tab.so > 1 || tab.we > 1)
		return (FAILURE);
	return (SUCCESS);
}

int	check_verif_2(t_verif tab)
{
	if (tab.c != 1 || tab.f != 1)
		return (FAILURE);
	if (tab.ea != 1 || tab.no != 1)
		return (FAILURE);
	if (tab.so != 1 || tab.we != 1)
		return (FAILURE);
	return (SUCCESS);
}
