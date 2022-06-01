/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_verif.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:30:02 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/18 11:31:59 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
