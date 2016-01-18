int		ft_max(int *tab, int length)
{
	int		cpt;
	int		max;

	cpt = 0;
	max = 0;
	while (cpt < lenght)
	{
		if (max < tab[cpt])
		{
			max = tab[cpt];
		}
		cpt++;
	}
	return (max);
}
