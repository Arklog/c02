char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	if (dest == 0 || src == 0)
		return 0;
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return dest;
}
