/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 08:04:33 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/04/08 20:52:36 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	chek_P(char **str, t_data *game)
{
	int	i;
	int	j;
	int	p;

	i = 0;
	p = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				game->px = i;
				game->py = j;
				p++;
			}
			j++;
		}
		i++;
	}
	if (p != 1)
		put_eror("you can have only one player\n");
}

int	chek_C(char **str)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (c == 0)
		put_eror("you need to have at least one colec in your map \n");
	return (c);
}


void	chek_E(char **str)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (e == 0)
		put_eror("you need to have at least one exit in your map \n");
}

int	chek_PCE(char **str, t_data *game)
{
	int i;
	chek_P(str, game);
	chek_E(str);
	i = chek_C(str);
	return(i);
}