int	str_is_uppercase(char* str)
{
	int	i;
	char	a;

	if(str == 0)
		return 0;
	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		if (!(a >= 65 && a <= 90))
			return 0;
		++i;
	}
	return 1;
}

int	str_is_lowercase(char *str)
{
	int	i;
	char	a;

	if (str == 0)
		return 0;
	i = 0;
	while (str[i] != '\0')
	{
		a = str[i];
		if (!(a >= 97 && a <= 122))
			return 0;
		++i;
	}
	return 1;
}

int	str_is_alpha(char *str)
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

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;
	char	a[2];

	i = 0;
	a[1] = '\0';
	new_word = 1;
	while (str[i] != '\0')
	{
		a[0] = str[i];
		
		if (new_word && str_is_alpha(a) && str_is_lowercase(a))
		{
			str[i] = a[0] - 32;
			new_word = 0;
		}
		else if (!new_word && str_is_alpha(a) && str_is_uppercase(a))
		{
			str[i] = a[0] + 32;
		}
		else if (a[0] == ' ')
			new_word = 1;
		else 
			new_word = 0;
		++i;
	}
	return str;
}
