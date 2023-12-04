/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkott <dkott@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:56:20 by dkott             #+#    #+#             */
/*   Updated: 2023/11/30 14:12:36 by dkott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct t_start
{
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playercount;
	int		collectablecount;
	int		exitcount;
	int		x_axis;
	int		y_axis;
	int		counter;
	int		collectables;

	char	**map;

	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlxpointer;
	void	*winpointer;

}	t_complete;

int			exit_game(t_complete *game);
int			map_reading(t_complete *game, char **argv);
int			handle_control(int command, t_complete *game);
int			handle_no_event(t_complete *game);
int			handle_input(int keysym, t_complete *game);
void		adding_in_play(t_complete *game);
void		adding_in_board(t_complete *game);
void		adding_elements(t_complete *game);
void		place_player(t_complete *game, int height, int width);
void		place_collectable(t_complete *game, int height, int width);
void		place_images_in_game(t_complete *game);
void		check_errors(t_complete *game);
void		init_null(t_complete *game);
void		character_valid(t_complete *game);
void		ft_free_map(char **map);
void		ft_free_img(t_complete *game);
void		flood_fill1(t_complete *game, char **map_cpy);
void		flood_fill2(t_complete *game, char **map_cpy);
void		check_path(t_complete *game);
void		check_window(t_complete *game);
t_point		get_pos_perso(t_complete *game);
char		**make_copy(char **map, t_complete *game);
size_t		ft_len(const char *s);

#endif