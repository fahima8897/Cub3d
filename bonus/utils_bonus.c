/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:02:04 by fboumell          #+#    #+#             */
/*   Updated: 2022/06/01 20:28:17 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	parse(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '.')
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

char	*strdup_no_n(const char *s1)
{
	char	*str;
	int		i;

	i = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_digit_size(int nb)
{
	if (nb > 255 || nb < 0)
		return (FAILURE);
	return (SUCCESS);
}

int	strlen_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
