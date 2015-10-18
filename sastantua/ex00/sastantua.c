/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <enaboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 14:24:21 by enaboule          #+#    #+#             */
/*   Updated: 2015/10/18 14:24:58 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_base(int floors)
{
	int		carac;
	int		carac_2;
	int		line;
	int		line_2;

	carac = 1;
	line = 3;
	line_2 = 0;
	carac_2 = 4;
	while (line < floors + 3)
	{
		while (line > line_2)
		{
			carac += 2;
			line_2++;
		}
		line_2 = 0;
		line++;
		if ((line - 2) % 2 == 0 && (line - 2) > 3)
			carac_2 += 2;
		if (line < floors + 3)
			carac += carac_2;
	}
	return (carac);
}

void	ft_door(int floors, int line, int carac, int cpt)
{
	int		cpt2;

	cpt2 = ft_base(floors) - ((floors + 2) - line) * 2;
	if (floors <= 2 && cpt == carac / 2 && cpt2 == carac)
		ft_putchar('|');
	else if (((floors == 3 && line >= 3) || (floors == 4 && line >= 4))
			&& (cpt <= carac / 2 + 1 && cpt >= carac / 2 - 1))
		ft_putchar('|');
	else if (floors >= 5 && ((line >= 3 && floors % 2 == 1) ||
				line >= 4))
	{
		if (((floors % 2 == 1 && line == floors + 2 - floors / 2) ||
					(floors % 2 == 0 && line == floors + 2 - floors / 2 + 1))
				&& cpt == carac / 2 + floors / 2 - 1)
			ft_putchar('$');
		else if (cpt <= carac / 2 + floors / 2 && cpt >= carac
				/ 2 - floors / 2)
			ft_putchar('|');
		else
			ft_putchar('*');
	}
	else
		ft_putchar('*');
	cpt++;
}

void	ft_aff(int floors, int line, int carac)
{
	int		cpt;
	int		cpt2;

	cpt2 = 0;
	cpt = ft_base(floors) - ((floors + 2) - line) * 2;
	while (cpt2 < cpt + (carac - cpt) / 2)
	{
		if (cpt2 < (carac - cpt) / 2)
			ft_putchar(' ');
		else if (cpt2 == (carac - cpt) / 2)
			ft_putchar('/');
		else if (cpt2 == cpt + (carac - cpt) / 2 - 1)
			ft_putchar('\\');
		else
		{
			if (ft_base(floors) != carac)
				ft_putchar('*');
			else
				ft_door(floors, line, carac, cpt2);
		}
		cpt2++;
	}
	ft_putchar('\n');
}

void	sastantua(int size)
{
	int		line;
	int		line_2;
	int		carac;

	line_2 = 0;
	line = 3;
	carac = ft_base(size);
	while (line < size + 3)
	{
		while (line > line_2)
		{
			line_2++;
			ft_aff(line - 2, line_2, carac);
		}
		line_2 = 0;
		line++;
	}
}
