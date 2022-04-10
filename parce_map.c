/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 03:15:44 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/04/10 06:52:58 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*line_map(int fd)
{
	char	*line;
	char	*map;
	char	*tmp;

	map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = map;
		map = ft_strjoin(map, line);
		free(tmp);
		free(line);
	}
	if (*map == '\0')
		put_eror("inser a correct map\n");
	multi_line(map);
	return (map);
}

char	**split_map(char *c)
{
	char	**spl_map;

	spl_map = ft_split(c, '\n');
	return (spl_map);
}

void	chek_wall(char **c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_2strlen(c) - 1;
	while (c[0][i])
	{
		if (c[0][i] != '1' || c[j][i] != '1')
		{
			put_eror("map not surrounded by walls\n");
		}
		i++;
	}
	i = 1;
	j = ft_strlen(c[1]) - 1;
	while (c[i])
	{
		if (c[i][0] != '1' || c[i][j] != '1')
			put_eror("map not surrounded by walls\n");
		i++;
	}
}
