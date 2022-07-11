int	ft_str_is_numeric(char *str)
{
	int	i;
	char	a;

	if (str == 0)
		return 0;
	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		if (!(a >= 48 && a <= 57))
			return 0;
		++i;
	}
	return 1;
}
