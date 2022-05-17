/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:14:49 by adaloui           #+#    #+#             */
/*   Updated: 2022/05/17 11:50:23 by fboumell         ###   ########.fr       */
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

t_verif check_split_content(char *str, t_verif check)
{
	if (str[0] == 'C' && str[1] == '\0')
		check.c++;
	if (str[0] == 'F' && str[1] == '\0')
		check.f++;
	if (str[0] == 'N' && str[1] == 'O' && str[2] == '\0')
		check.no++;
	if (str[0] == 'S' && str[1] == 'O' && str[2] == '\0')
		check.so++;
	if (str[0] == 'E' && str[1] == 'A' && str[2] == '\0')
		check.ea++;
	if (str[0] == 'W' && str[1] == 'E' && str[2] == '\0')
		check.we++;
	return (check);
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
	t_verif check;

	check = verif_init();
	i = 0;
	while (map->map[i])
	{
		split_byspace = ft_split(map->map[i], ' ');
		j = 0;
		while (split_byspace[j])
		{
			check = check_split_content(split_byspace[j], check);
			free(split_byspace[j]);
			j++;
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
int	check_opt_argv_map(char *argv)
{
	t_map	*map;

	map = create_map(argv);
	if (check_map_content(map) == FAILURE)
	{
		free_struct(map);
		return (FAILURE);
	}
	free_struct(map);
	return (SUCCESS);
}
