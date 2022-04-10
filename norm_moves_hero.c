/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_moves_hero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 06:44:59 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/04/10 07:38:55 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	norm_w(t_data *game)
{
	if (game->map[game->px - 1][game->py] == 'E' && game->i == 0)
		return (0);
	if (game->map[game->px - 1][game->py] == 'E' && game->i == 1)
		exit(1);
	norm_manag(game, 'w');
	return (3);
}

int	norm_s(t_data *game)
{
	if (game->map[game->px + 1][game->py] == 'E' && game->i == 0)
		return (0);
	if (game->map[game->px + 1][game->py] == 'E' && game->i == 1)
		exit(1);
	norm_manag(game, 's');
	return (3);
}

int	norm_d(t_data *game)
{
	if (game->map[game->px][game->py + 1] == 'E' && game->i == 0)
		return (0);
	if (game->map[game->px][game->py + 1] == 'E' && game->i == 1)
		exit(1);
	norm_manag(game, 'd');
	return (3);
}

int	norm_a(t_data *game)
{
	if (game->map[game->px][game->py - 1] == 'E' && game->i == 0)
		return (0);
	if (game->map[game->px][game->py - 1] == 'E' && game->i == 1)
		exit(1);
	norm_manag(game, 'a');
	return (3);
}

void	main_norm(t_data *game, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->empty, (j * 64), (i * 64));
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall, (j * 64), (i * 64));
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->hero, (j * 64), (i * 64));
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->colec, (j * 64), (i * 64));
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exi, (j * 64), (i * 64));
}
