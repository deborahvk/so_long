/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkott <dkott@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:52:34 by dkott             #+#    #+#             */
/*   Updated: 2023/11/30 11:09:13 by dkott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_checker(t_complete *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		ft_printf("\nError Here!%c\n", game->map[height][width]);
		exit_game(game);
	}
	if (game->map[height][width] == 'C')
			game->collectablecount++;
	if (game->map[height][width] == 'P')
			game->playercount++;
	if (game->map[height][width] == 'E')
			game->exitcount++;
}

void	error_message(t_complete *game)
{
	if (game->playercount != 1)
		ft_printf ("Incorrect number of player\n");
	if (game->collectablecount < 1)
		ft_printf ("Incorrect number of collectable items\n");
	if (game->exitcount != 1)
		ft_printf ("Incorrect number of exit\n");
}

void	character_valid(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->heightmap - 1)
	{
		width = 0;
		while (width <= game->widthmap)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercount == 1 && game->collectablecount >= 1
			&& game->exitcount == 1))
	{
		ft_printf("Error\nSomething is wrong!\n");
		error_message(game);
		exit_game(game);
	}
}

void	check_window(t_complete *game)
{
	int	sizex;
	int	sizey;

	sizex = 0;
	sizey = 0;
	game->mlxpointer = mlx_init();
	if (!(game->mlxpointer))
		exit_game(game);
	mlx_get_screen_size(game->mlxpointer, &sizex, &sizey);
	if (sizex < (52 * game->widthmap) || sizey < (52 * game->heightmap))
	{
		ft_printf("Error\n The map is bigger than the screen !\n");
		exit_game(game);
	}	
}
