/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkott <dkott@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:53:29 by dkott             #+#    #+#             */
/*   Updated: 2023/11/29 14:17:54 by dkott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	keyboard_down(t_complete *game)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	j++;
	if (game->map[j][i] == '1')
		return (0);
	if (game->map[j][i] == 'E' && game->collectables != 0)
		return (0);
	if (game->map[j][i] == 'E' && game->collectables == 0)
	{
		ft_printf("Congrats ! You won !\n");
		ft_printf("Steps Taken: %i\n", (game->counter + 1));
		ft_printf("Collectables Left: %i\n", game->collectables);
		exit_game(game);
	}
	game->map[j - 1][i] = '0';
	game->map[j][i] = 'P';
	game->counter++;
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_up(t_complete *game)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	j--;
	if (game->map[j][i] == '1')
		return (0);
	if (game->map[j][i] == 'E' && game->collectables != 0)
		return (0);
	if (game->map[j][i] == 'E' && game->collectables == 0)
	{
		ft_printf("Congrats ! You won !\n");
		ft_printf("Steps Taken: %i\n", (game->counter + 1));
		ft_printf("Collectables Left: %i\n", game->collectables);
		exit_game(game);
	}
	game->map[j + 1][i] = '0';
	game->map[j][i] = 'P';
	game->counter++;
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_right(t_complete *game)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	i++;
	if (game->map[j][i] == '1')
		return (0);
	if (game->map[j][i] == 'E' && game->collectables != 0)
		return (0);
	if (game->map[j][i] == 'E' && game->collectables == 0)
	{
		ft_printf("Congrats ! You won !\n");
		ft_printf("Steps Taken: %i\n", (game->counter + 1));
		ft_printf("Collectables Left: %i\n", game->collectables);
		exit_game(game);
	}
	game->map[j][i - 1] = '0';
	game->map[j][i] = 'P';
	game->counter++;
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_left(t_complete *game)
{
	int	i;
	int	j;

	i = game->x_axis;
	j = game->y_axis;
	i--;
	if (game->map[j][i] == '1')
		return (0);
	if (game->map[j][i] == 'E' && game->collectables != 0)
		return (0);
	if (game->map[j][i] != 'E')
		game->map[j][i + 1] = '0';
	if (game->map[j][i] == 'E' && game->collectables == 0)
	{
		ft_printf("Congrats ! You won !\n");
		ft_printf("Steps Taken: %i\n", (game->counter + 1));
		ft_printf("Collectables Left: %i\n", game->collectables);
		exit_game(game);
	}
	game->map[j][i] = 'P';
	game->counter++;
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

int	handle_input(int keysym, t_complete *game)
{
	if (keysym == XK_Escape)
		exit_game(game);
	if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
		keyboard_left(game);
	if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
		keyboard_right(game);
	if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
		keyboard_up(game);
	if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
		keyboard_down(game);
	return (0);
}
