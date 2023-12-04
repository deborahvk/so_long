/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkott <dkott@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:30:18 by dkott             #+#    #+#             */
/*   Updated: 2023/11/30 09:12:57 by dkott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map1(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C' || map[j][i] == 'P')
			{
				ft_printf("Error\n Invalid path.\n");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	check_map2(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
			{
				ft_printf("Error\n Invalid path.\n");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	check_path(t_complete *game)
{
	char	**map_cpy;

	map_cpy = make_copy(game->map, game);
	if (!map_cpy)
	{
		ft_printf("Error with map checking.\n");
		exit_game(game);
		exit (0);
	}
	flood_fill1(game, map_cpy);
	if (check_map1(map_cpy) != 0)
	{
		ft_free_map(map_cpy);
		exit_game(game);
		exit (0);
	}
	flood_fill2(game, map_cpy);
	if (check_map2(map_cpy) != 0)
	{
		ft_free_map(map_cpy);
		exit_game(game);
		exit (0);
	}
	ft_free_map(map_cpy);
}
