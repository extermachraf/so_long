/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_tani.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 07:41:58 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/04/10 07:49:07 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	norm_ww(t_data *game)
{
	game->map[game->px][game->py] = '0';
	game->map[game->px - 1][game->py] = 'P';
	game->px--;
	ft_putnbr(game->m++);
	ft_putchar('\n');
}

void	norm_dd(t_data *game)
{
	game->map[game->px][game->py] = '0';
	game->map[game->px][game->py + 1] = 'P';
	game->py++;
	ft_putnbr(game->m++);
	ft_putchar('\n');
}

void	norm_ss(t_data *game)
{
	game->map[game->px][game->py] = '0';
	game->map[game->px + 1][game->py] = 'P';
	game->px++;
	ft_putnbr(game->m++);
	ft_putchar('\n');
}

void	norm_aa(t_data *game)
{
	game->map[game->px][game->py] = '0';
	game->map[game->px][game->py - 1] = 'P';
	game->py--;
	ft_putnbr(game->m++);
	ft_putchar('\n');
}
