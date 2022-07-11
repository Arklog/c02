char	*ft_strupcase(char *str)
{
	int	i;
	char	a;

	if (str == 0)
		return 0;
	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		if (a >= 97 && a <= 122)
			str[i] = a - 32;
		++i;
	}
	return str;
}
