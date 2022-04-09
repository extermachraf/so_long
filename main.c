/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:17:15 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/04/09 03:41:07 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
char **return_map(char *av)
{
	char	*map;
	char	**spl_map;
	int		i;
	int fd;
	
	i = 0;
	fd = open(av, O_RDONLY);
	map = line_map(fd);
	spl_map = split_map(map);
	close(fd);
	return(spl_map);
}

void	display_ground(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->empty, (j * 64), (i * 64));
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, (j * 64), (i * 64));
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->hero, (j * 64), (i * 64));
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->colec, (j * 64), (i * 64));
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exi, (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}
int		calc_lent(t_data *game, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(game->map[i])
		i++;
	while(game->map[0][j])
		j++;
	if(c == 'x')
		return(j);
	else if(c == 'y')
		return(i);
	return(0);
}

void	fill_map(t_data *game)
{
	game->empty = mlx_xpm_file_to_image(game->mlx, "ac.xpm", &game->x, &game->y);
	game->wall = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &game->x, &game->y);
	game->hero = mlx_xpm_file_to_image(game->mlx, "hero.xpm", &game->x, &game->y);
	game->colec = mlx_xpm_file_to_image(game->mlx, "ramen.xpm", &game->x, &game->y);
	game->exi = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &game->x, &game->y);
}

int management(int keycode, t_data *game)
{
	printf("%d\n", keycode);
	if(keycode == 13 && game->map[game->px - 1][game->py] != '1')
	{
		game->map[game->px][game->py] = '0';
		game->map[game->px - 1][game->py] = 'P';
		game->px--;
	}
	else if(keycode == 1 && game->map[game->px + 1][game->py] != '1')
	{
		game->map[game->px][game->py] = '0';
		game->map[game->px + 1][game->py] = 'P';
		game->px++;
	}
	else if(keycode == 2 && game->map[game->px][game->py + 1] != '1')
	{
		game->map[game->px][game->py] = '0';
		game->map[game->px][game->py + 1] = 'P';
		game->py++;
	}
	else if(keycode == 0 && game->map[game->px][game->py - 1] != '1')
	{
		game->map[game->px][game->py] = '0';
		game->map[game->px][game->py - 1] = 'P';
		game->py--;
	}
	display_ground(game);
	return (1);
}
int main(int ac, char **av)
{
	t_data	game;
	int		c;

	c = 0;
	game.map = return_map(av[1]);
	chek_wall(game.map);
	c = chek_PCE(game.map, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (ft_strlen(game.map[0]) * 64), (ft_2strlen(game.map) * 64), "solong");
	fill_map(&game);
	display_ground(&game);
	mlx_key_hook(game.win, management, &game);
	mlx_loop(game.mlx);
}
