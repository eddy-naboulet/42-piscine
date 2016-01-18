int		ft_unmatch(int *tab, int lenght)
{
	int		cpt;
	int		cpt2;
	int		find;

	cpt = 0;
	cpt2 = 0;
	find = 0;
	while (cpt < lenght)
	{
		while ( cpt2 < lenght)
		{
			if (tab[cpt] == tab[cpt2])
			{
				find = 1;
			}
			cpt2++;
		}
		if (find == 0)
			return (tab[cpt]);
		find = 0;
		cpt++;
	}
	return (0);
}
