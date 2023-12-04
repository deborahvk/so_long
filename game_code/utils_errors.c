/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkott <dkott@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:50:12 by dkott             #+#    #+#             */
/*   Updated: 2023/11/30 14:12:19 by dkott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

t_point	get_pos_perso(t_complete *game)
{
	t_point	pos;
	int		height;
	int		width;

	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == 'P')
			{
				pos.x = width;
				pos.y = height;
			}
			width++;
		}
		height++;
	}
	return (pos);
}

char	**make_copy(char **map, t_complete *game)
{
	char	**copy;
	int		i;

	if (!map)
		return (NULL);
	copy = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->heightmap)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			ft_free_map(copy);
			exit_game(game);
		}
		i++;
	}
	copy[i] = 0;
	return (copy);
}
