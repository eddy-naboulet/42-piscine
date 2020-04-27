void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int		h;
	int		i;
	int		j;

	h = *b;
	i = ****d;
	j = *******c;
	*******c = ***a;
	****d = j;
	*b = h;
	***a = i;
}
