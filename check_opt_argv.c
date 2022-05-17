/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:14:49 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/17 17:24:50 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*int	check_compo_map(char **map)
{
	int		i;
	int		j;
	t_verif	check;

	i = 0;
	// printf("check = %lld\n", check.c);
	while (map[i])
	{
		j = 0;
		// printf("%s", map[i]);
		while (map[i][j])
		{
			if (check.c == 1 && check.c == 1 && check.f == 1 && check.no == 1
				&& check.so == 1 && check.we == 1)
			{
				// printf("check = %lld\n", check.c);
				i++;
			}
			if (map[i][j] != ' ' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E'
				&& map[i][j] != 'W')
			{
				write_errors("Errors\nAt least one of the component is wrong");
				return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}*/

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
	if (tab.c != 1 || tab.f != 1)
		return (FAILURE);
	if (tab.ea != 1 || tab.no != 1)
		return (FAILURE);
	if (tab.so != 1 || tab.we != 1)
		return (FAILURE);
	return (SUCCESS);
}

/*JE VAIS CHANGER LA FORET DE IF, JE PENSE A UTILISER DES POINTEURS SUR FONCTIONS */

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

char	*ft_strdup_no_n(const char *s1)
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

/* FONCTION QUI SPLIT NOTRE LIGNE PAR ESPACE ET QUI CHECK LA PRESENCE DE NO SO WE EA F ET C*/
/* POUR LE MOMENT, ELLE RENVOIT QUE SUCCESS */
/* PAS TERMINER, IL FAUT ETENDRE LES CAS DE FIGURES TRAITES ET FAIRE UNE FONCTION PLUS GENERALE*/
/* SINON LE PROGRAMME SAUTERA TROP FACILEMENT */

int		check_map_content(t_map *map)
{
	int		i;
	int		j;
	char	**split_byspace;
	t_verif	check;
	char	*tmp;

	check = verif_init();
	i = 0;
	while (map->map[i] && i < 5)
	{
		split_byspace = ft_split(map->map[i], ' ');
		j = 0;
		printf("split == [%c]", split_byspace[j][1]);
		if (split_byspace[j][0] == '\n')
		{
			while (split_byspace[j])
			{
				tmp = ft_strdup_no_n(split_byspace[1]);
				check = check_split_content(split_byspace[j], tmp, check);
				free(split_byspace[j]);
				free(tmp);
				j++;
			}
		}
		free(split_byspace);
		i++;
	}
/* IL FAUT QUE JE PENSE A UNE REELLE ARCHITECTURE D ERREURS*/
/* IL FAUT QUE CETTE FONCTION (OU PLUSIEURS) CHECK S'IL Y'A BIEN NO SO WE EA */
/* PUIS TENTE D'OPEN LE FICHIER QUI EST A COTE */
/* PAREIL POUR F ET C MAIS AVEC LES DONNEES DE COULEURS */

	printf ("2 check.c == %lld\n", check.c);
	printf ("2 check.f == %lld\n", check.f);
	printf ("2 check.ea == %lld\n", check.ea);
	printf ("2 check.no == %lld\n", check.no);
	printf ("2 check.so == %lld\n", check.so);
	printf ("2 check.we == %lld\n", check.we);
	if (check_verif(check) == FAILURE)
		return (return_failure("Error.\nProblem with textures."));
	return (SUCCESS);
}

/* CA LEAKS PLUS ET CA RENVOIT BIEN LA MAP SANS AUCUN SOUCIS */
/* Si il y'a un probleme avec les textures == FAILURE*/
int	check_opt_argv_map(char *argv, t_data *data)
{
	data->map = create_map(argv, data);
	if (check_map_content(data->map) == FAILURE)
	{
		free_struct(data->map);
		return (FAILURE);
	}
	return (SUCCESS);
}
