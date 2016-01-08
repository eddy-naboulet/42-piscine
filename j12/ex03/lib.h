/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboul@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 21:11:50 by enaboule          #+#    #+#             */
/*   Updated: 2016/01/08 22:52:22 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# define B 9600

# define FILEBIS "filebis"

# include <unistd.h>
# include <fcntl.h>

void	ft_bs(int nbr, char *base);
void	ft_putnbr_base(int nbr, char *base);
void	ft_zero(unsigned int cpt, int p);
void	ft_sym(int nb, int rc, char *buf, int p);
void	ft_error(int cpt, int argc, char *file);
int		ft_hx(char *buf, int wr, int p);
int		ft_strlen(char *str);
void	ft_space(int nbr, int p);

#endif
