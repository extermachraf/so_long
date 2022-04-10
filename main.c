/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:17:15 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/04/10 07:40:26 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**return_map(char *av)
{
	char	*map;
	char	**spl_map;
	int		i;
	int		fd;

	i = 0;
	fd = open(av, O_RDONLY);
	map = line_map(fd);
	spl_map = split_map(map);
	close(fd);
	return (spl_map);
}

void	display_ground(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			main_norm(game, i, j);
			j++;
		}
		i++;
	}
}

int	calc_lent(t_data *game, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
		i++;
	while (game->map[0][j])
		j++;
	if (c == 'x')
		return (j);
	else if (c == 'y')
		return (i);
	return (0);
}

void	fill_map(t_data *game)
{
	game->empty = mlx_xpm_file_to_image(game->mlx,
			"ac.xpm", &game->x, &game->y);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"wall.xpm", &game->x, &game->y);
	game->hero = mlx_xpm_file_to_image(game->mlx,
			"hero.xpm", &game->x, &game->y);
	game->colec = mlx_xpm_file_to_image(game->mlx,
			"ramen.xpm", &game->x, &game->y);
	game->exi = mlx_xpm_file_to_image(game->mlx,
			"exit.xpm", &game->x, &game->y);
}

int	main(int ac, char **av)
{
	t_data	game;
	int		c;

	if (ac == 2)
	{
		game.m = 0;
		chek_folder(av[1]);
		game.map = return_map(av[1]);
		global_err(&game);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, (ft_strlen(game.map[0]) * 64),
				(ft_2strlen(game.map) * 64), "solong");
		fill_map(&game);
		display_ground(&game);
		mlx_key_hook(game.win, management, &game);
		mlx_hook(game.win, 17, 1L << 0, exit_mouse, &game);
		mlx_loop(game.mlx);
	}
	else
		put_eror("Error");
}
