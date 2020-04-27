/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afougere <afougere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:04:18 by afougere          #+#    #+#             */
/*   Updated: 2016/01/15 11:01:21 by afougere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# define BUF_SIZE 6000

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_square
{
	int			x;
	int			y;
	int			w;
	int			h;
}				t_square;

typedef struct	s_def_map
{
	char		plein;
	char		obstacle;
	char		vide;
	char		** map;
	char		*str;
	char		*map_size;
	int			size;
	int			line_size;
}				t_def_map;

t_def_map		read_header(char *file, int *fd);
char			**read_square(char *file, t_def_map *car);
char			**read_square_bis(int fd, t_def_map car, char **tab);
int				count_car(char *file);
int				ft_error_bis(char **tab, t_def_map car);
int				verif_square(char **tab, t_def_map symbole);
int				verif_place_square(char **tab, t_square place, t_def_map carr);
char			**resolve_square(char **tab, t_def_map car);
void			map_error();
void			print_square(char **tab);
int				ft_atoi(char *str);
int				verif_header(char *str);

#endif
