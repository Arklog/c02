int	ft_str_is_printable(char *str)
{
	int	i;
	char	a;

	if (str == 0)
		return 0;
	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		if (!(a >= 32 && a <= 127))
			return 0;
		++i;
	}
	return 1;
}
