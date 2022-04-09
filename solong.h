/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:15:46 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/04/09 03:38:33 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>
# define BUFFER_SIZE 10

typedef struct	s_data {
	void	*empty;
	int		x;
	int		y;
	char	**map;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*hero;
	void	*colec;
	void	*exi;
	int		px;
	int		py;
}	t_data;

typedef struct	r_data {
	int	i;
	int	j;
	int	p;
	int	c;
	int e;
}	t_parc;

int		ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char	*s, int c);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*line_map(int fd);
char	**split_map(char *c);
int		ft_2strlen(char **str);
void	ft_putstr(char *c);
void	chek_wall(char **c);
void	put_eror(char *c);
void	chek_P(char **str, t_data *game);
int		chek_C(char **str);
void	chek_E(char **str);
int		chek_PCE(char **str, t_data *game);

#endif