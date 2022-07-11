char	*ft_strlowcase(char *str)
{
	int	i;
	char	a;

	if (str == 0)
		return 0;
	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		if (a >= 65 && a <= 90)
			str[i] = a + 32;
		++i;
	}
	return str;
}
