unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	tmp;
	char		a;

	if (dest == 0 || src == 0)
		return 0;
	i = 0;
	while (i < n - 1 && src[i] != '\0')
	{
		a = src[i];
		dest[i] = a;
		++i;
	}
	if ( ++i < n)
		dest[i] = '\0';
	else
		dest[--i] = '\0';
	return i;
}
