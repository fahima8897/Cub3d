/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:38:43 by fboumell          #+#    #+#             */
/*   Updated: 2022/05/12 17:34:02 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>

	/* returns */
# define SUCCESS 0
# define FAILURE -1

	/* main.c */
int	ft_strcmp(char *s1, char *s2);
int	parse(char *av);
int	check_format_map(char *av);
int	main(int ac, char **av);

#endif
