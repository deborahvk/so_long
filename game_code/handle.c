/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkott <dkott@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:49:51 by dkott             #+#    #+#             */
/*   Updated: 2023/11/14 11:20:34 by dkott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_complete *game)
{
	adding_in_board(game);
	adding_in_play(game);
	return (0);
}
/*int	handle_keypress(int keysym, t_complete *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(game->mlxpointer, game->winpointer);
		free(game->mlxpointer);
		exit (0);
	}
	return (0);
}*/
/*int	handle_input(int keysym, t_complete *game)
{
	if (keysym == XK_Escape)
		ft_free(game);
	if (keysym == XK_a || keysym == XK_A)
		keyboard_left(game);
	if (keysym == XK_d || keysym == XK_D)
		keyboard_right(game);
	if (keysym == XK_w || keysym == XK_W)
		keyboard_up(game);
	if (keysym == XK_s || keysym == XK_S)
		keyboard_down(game);
	return (0);
}*/