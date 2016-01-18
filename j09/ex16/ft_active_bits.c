unsigned int	ft_active_bits(int value)
{
	unsigned int	cpt;
	unsigned int	cpt2;

	cpt = 0;
	cpt2 = (unsigned int)value;
	while (cpt2 != 0)
	{
		cpt += cpt2 & 1;
		cpt2 >>= 1;
	}
	return (cpt);
}
