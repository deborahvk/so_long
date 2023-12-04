/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkott <dkott@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:09:25 by dkott             #+#    #+#             */
/*   Updated: 2023/11/29 10:30:32 by dkott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_filled(char c, char *to_fill)
{
	int	i;

	i = 0;
	while (to_fill[i])
	{
		if (c == to_fill[i])
			return (1);
		i++;
	}
	return (0);
}

void	fill1(char **map, t_point cur, t_point size, char *to_fill)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y
		|| !is_filled(map[cur.y][cur.x], to_fill))
		return ;
	map[cur.y][cur.x] = 'x';
	fill1(map, (t_point){cur.x - 1, cur.y}, size, to_fill);
	fill1(map, (t_point){cur.x + 1, cur.y}, size, to_fill);
	fill1(map, (t_point){cur.x, cur.y - 1}, size, to_fill);
	fill1(map, (t_point){cur.x, cur.y + 1}, size, to_fill);
}

void	flood_fill1(t_complete *game, char **map_cpy)
{
	char	to_fill[4];
	t_point	begin;
	t_point	size;

	begin = get_pos_perso(game);
	size.x = game->widthmap;
	size.y = game->heightmap;
	to_fill[0] = '0';
	to_fill[1] = 'C';
	to_fill[2] = 'P';
	to_fill[3] = '\0';
	fill1(map_cpy, begin, size, to_fill);
}

void	fill2(char **map, t_point cur, t_point size, char *to_fill)
{
	if (cur.x < 0 || cur.x >= size.x || cur.y < 0 || cur.y >= size.y
		|| !is_filled(map[cur.y][cur.x], to_fill))
		return ;
	map[cur.y][cur.x] = 'y';
	fill2(map, (t_point){cur.x - 1, cur.y}, size, to_fill);
	fill2(map, (t_point){cur.x + 1, cur.y}, size, to_fill);
	fill2(map, (t_point){cur.x, cur.y - 1}, size, to_fill);
	fill2(map, (t_point){cur.x, cur.y + 1}, size, to_fill);
}

void	flood_fill2(t_complete *game, char **map_cpy)
{
	char	to_fill[3];
	t_point	begin;
	t_point	size;

	begin = get_pos_perso(game);
	size.x = game->widthmap;
	size.y = game->heightmap;
	to_fill[0] = 'x';
	to_fill[1] = 'E';
	to_fill[2] = '\0';
	fill2(map_cpy, begin, size, to_fill);
}
