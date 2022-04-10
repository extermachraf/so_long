/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:15:46 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/04/10 07:45:43 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 10

typedef struct s_data {
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
	int		i;
	int		m;
}	t_data;

typedef struct r_data {
	int	i;
	int	j;
	int	p;
	int	c;
	int	e;
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
int		chek_pce(char **str, t_data *game);
int		management(int keycode, t_data *game);
void	display_ground(t_data *game);
void	norm_manag(t_data *game, char c);
int		chek_exit(char **game);
int		norm_w(t_data *game);
int		norm_s(t_data *game);
int		norm_d(t_data *game);
int		norm_a(t_data *game);
void	ft_putchar(char c);
void	norm1_manag(t_data *game, char c);
void	ft_putnbr(int n);
void	chek_carac(t_data *game);
void	chek_rect(t_data *game);
void	chek_folder(char *av);
void	global_err(t_data *game);
void	check_last(t_data *game);
void	multi_line(char *c);
int		exit_mouse(int key);
void	main_norm(t_data *game, int i, int j);
void	norm_ww(t_data *game);
void	norm_dd(t_data *game);
void	norm_ss(t_data *game);
void	norm_aa(t_data *game);
#endif