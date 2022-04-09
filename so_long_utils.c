/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:56:18 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/04/08 06:13:49 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int ft_2strlen(char **str)
{
	int i;
	
	i = 0;
	if(!str)
		return(0);
	while (str[i])
		i++;
	return(i);
}

void	ft_putstr(char *c)
{
	int i;

	i = 0;
	while(c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
}

void	put_eror(char *c)
{
	ft_putstr(c);
	exit(0);
}