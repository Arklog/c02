int	ft_str_is_alpha(char* str)
{
	int	i;
	char	a;

	if (str == 0)
		return 0;
	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		if (!(a >= 65 && a <= 90) && !(a >= 97 && a <= 122))
			return 0;
		++i;
	}
	return 1;
}
