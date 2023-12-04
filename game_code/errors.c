/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkott <dkott@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:53:53 by dkott             #+#    #+#             */
/*   Updated: 2023/12/04 10:32:10 by dkott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	rectangular_map(t_complete *game)
{
	int		i;
	size_t	length;

	i = 1;
	length = ft_len(game->map[0]);
	while (i < game->heightmap)
	{
		while (i < game->heightmap)
		{
			if (!(ft_len(game->map[i]) == length))
				return (0);
			i++;
		}	
		i++;
	}
	return (1);
}

static int	horizontalwall(t_complete *game)
{
	int	height;
	int	width;

	width = 0;
	height = game->heightmap;
	while (width < game->widthmap)
	{
		if (!(game->map[0][width] == '1'
			&& game->map[height - 1][width] == '1'))
			return (0);
		width++;
	}
	return (1);
}

static int	verticalwall(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->widthmap;
	while (height < game->heightmap)
	{
		if (!(game->map[height][0] == '1'
			&& game->map[height][width - 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

static void	if_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;
	int	rectangularmap;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	rectangularmap = rectangular_map(game);
	if (!verticalwalls || !horizontalwalls || !rectangularmap)
	{
		ft_printf("Error\nSomething is wrong with the walls\n");
		exit_game(game);
	}
}

void	check_errors(t_complete *game)
{
	check_window(game);
	if_walls(game);
	character_valid(game);
	check_path(game);
}
