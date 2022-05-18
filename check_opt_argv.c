/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:14:49 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/18 11:35:28 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	check_verif(t_verif tab)
// {
// 	if (tab.c != 1 || tab.f != 1)
// 		return (FAILURE);
// 	if (tab.ea != 1 || tab.no != 1)
// 		return (FAILURE);
// 	if (tab.so != 1 || tab.we != 1)
// 		return (FAILURE);
// 	return (SUCCESS);
// }

t_verif check_split_content(char *str, char *file, t_verif check)
{
	if (str[0] == 'C' && str[1] == '\0')
		check.c++;
	if (str[0] == 'F' && str[1] == '\0')
		check.f++;
	if (str[0] == 'N' && str[1] == 'O' && str[2] == '\0')
	{
		if (open(file, O_RDONLY) < 0)
			printf("Error\nCannot open file.\n");
		else
			printf("Open successfull NO.\n");
		check.no++;
	}
	if (str[0] == 'S' && str[1] == 'O' && str[2] == '\0')
	{
		check.so++;
		if (open(file, O_RDONLY) < 0)
			printf("Error\nCannot open file.\n");
		else
			printf("Open successfull SO.\n");
	}
	if (str[0] == 'E' && str[1] == 'A' && str[2] == '\0')
	{		
		if (open(file, O_RDONLY) < 0)
			printf("Error\nCannot open file.\n");
		else
			printf("Open successfull EA.\n");
		check.ea++;
	}
	if (str[0] == 'W' && str[1] == 'E' && str[2] == '\0')
	{
		if (open(file, O_RDONLY) < 0)
			printf("Error\nCannot open file.\n");
		else
			printf("Open successfull WE.\n");
		check.we++;
	}
	return (check);
}

/*char	*ft_strdup_no_n(const char *s1)
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
}*/

/*int		check_map_content(t_map *map)
{
	int		i;
	int		j;
	char	**split_byspace;
	t_verif	check;
	char	*tmp;

	check = verif_init();
	i = 0;
	while (map->map[i] && i < 20)
	{
		if (map->map[i][0] != '\n')
		{
			split_byspace = ft_split(map->map[i], ' ');
			j = 0;
			while (split_byspace[j])
			{
				tmp = ft_strdup_no_n(split_byspace[1]);
				check = check_split_content(split_byspace[j], tmp, check);
				free(split_byspace[j]);
				free(tmp);
				j++;
			}
			free(split_byspace);
		}
		printf("map : [%s]\n", map->map[i]);
		i++;
	}
	printf ("2 check.c == %lld\n", check.c);
	printf ("2 check.f == %lld\n", check.f);
	printf ("2 check.ea == %lld\n", check.ea);
	printf ("2 check.no == %lld\n", check.no);
	printf ("2 check.so == %lld\n", check.so);
	printf ("2 check.we == %lld\n", check.we);
	if (check_verif(check) == FAILURE)
		return (return_failure("Error.\nProblem with textures.\n"));
	return (SUCCESS);
}*/

int	check_opt_argv_map(char *argv, t_data *data)
{
	data->map = create_map(argv, data);
	if (check_line_content(data->map) == FAILURE)
	{
		free_struct(data->map);
		return (FAILURE);
	}
/*	if (check_map_content(data->map) == FAILURE)
	{
		free_struct(data->map);
		return (FAILURE);
	}*/
	return (SUCCESS);
}
