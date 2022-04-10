/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 05:30:00 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/04/10 07:47:56 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	chek_exit(char **game)
{	
	int	i;
	int	j;

	i = 0;
	while (game[i])
	{
		j = 0;
		while (game[i][j])
		{
			if (game[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	norm_manag(t_data *game, char c)
{
	if (c == 'w')
		norm_ww(game);
	else if (c == 'd')
		norm_dd(game);
	else if (c == 's')
		norm_ss(game);
	else if (c == 'a')
		norm_aa(game);
}

int	management(int keycode, t_data *game)
{	
	game->i = chek_exit(game->map);
	if (keycode == 53 || keycode == 12)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (keycode == 13 && game->map[game->px - 1][game->py] != '1')
		norm_w(game);
	else if (keycode == 1 && game->map[game->px + 1][game->py] != '1')
		norm_s(game);
	else if (keycode == 2 && game->map[game->px][game->py + 1] != '1')
		norm_d(game);
	else if (keycode == 0 && game->map[game->px][game->py - 1] != '1')
		norm_a(game);
	display_ground(game);
	return (1);
}

int	exit_mouse(int key)
{
	if (key < 0)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	return (0);
}
