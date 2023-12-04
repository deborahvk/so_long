/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkott <dkott@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:54:53 by dkott             #+#    #+#             */
/*   Updated: 2023/11/30 09:21:57 by dkott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->heightmap++;
	temporary = (char **)malloc(sizeof(char *) * (game->heightmap + 1));
	if (!temporary)
		return (0);
	temporary[game->heightmap] = NULL;
	while (i < game->heightmap - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	map_reading(t_complete *game, char **argv)
{
	char	*readmap;
	int		i;

	i = ft_strlen(argv[1]) - 1;
	if (!(argv[1][i] == 'r' && argv[1][i - 1] == 'e' && argv[1][i - 2] == 'b'
			&& argv[1][i - 3] == '.'))
		exit_game (game);
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		exit_game(game);
		return (0);
	}
	while (1)
	{
		readmap = get_next_line(game->fd);
		if (!add_line(game, readmap))
			break ;
	}
	close (game->fd);
	if (game->map == NULL)
		exit_game(game);
	game->widthmap = width_of_map(game->map[0]);
	return (1);
}

void	init_null(t_complete *game)
{
	game->floor = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->collectable = NULL;
}
