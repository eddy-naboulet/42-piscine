#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int		cpt;
	int		cpt2;

	cpt = 0;
	cpt2 = 0;
	while (s1[cpt] != '\0')
	{
		if (s1[cpt] >= 65 && s1[cpt] <= 90)
			s1[cpt] += 97 - 65;
		cpt++;
	}
	cpt = 0;
	while (s1[cpt] == ' ' || s1[cpt] == '\t' || s1[cpt] == '\n')
		cpt++;
	while ((s1[cpt] == s2[cpt2] && s1[cpt] != '\0'))
	{
		cpt++;
		cpt2++;
	}
	return (s1[cpt] - s2[cpt2]);
}

int		main(int argc, char **argv)
{
	int		cpt;
	int		cpt2;

	cpt = 0;
	cpt2 = 1;
	while (cpt < argc)
	{
		cpt2 *= ft_strcmp(argv[cpt], "president");
		cpt2 *= ft_strcmp(argv[cpt], "attack");
		cpt2 *= ft_strcmp(argv[cpt], "powers");
		cpt++;
	}
	if (cpt2 == 0)
		write(1, "Alert!!!\n", 9);
	return (0);
}
