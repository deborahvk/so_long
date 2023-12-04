/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkott <dkott@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:55:12 by dkott             #+#    #+#             */
/*   Updated: 2023/11/29 14:06:38 by dkott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*fct_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

int	handle_keypress(int keysym, t_complete *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlxpointer, game->winpointer);
		free(game->mlxpointer);
		exit (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_complete	game;

	if (argc != 2)
		return (0);
	fct_memset(&game, 0, sizeof(t_complete));
	init_null(&game);
	map_reading(&game, argv);
	check_errors(&game);
	game.winpointer = mlx_new_window(game.mlxpointer, (game.widthmap * 52),
			(game.heightmap * 52), "solong");
	if (!(game.winpointer))
		exit_game(&game);
	place_images_in_game(&game);
	adding_elements(&game);
	mlx_loop_hook(game.mlxpointer, &handle_no_event, &game);
	mlx_hook(game.winpointer, KeyPress, KeyPressMask, &handle_input, &game);
	mlx_hook(game.winpointer, ClientMessage, NoEventMask, &exit_game, &game);
	mlx_hook(game.winpointer, 17, 0, &exit_game, &game);
	mlx_loop(game.mlxpointer);
	free(game.mlxpointer);
	mlx_destroy_display(game.mlxpointer);
	return (0);
}
