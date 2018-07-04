char	*my_strncat(char *dest, char *src, int n)
{
	int i;
	int j;
	i = 0;
	j = 0;
	while (*dest != '\0')
	{
		dest++;
		j++;
	}
	while (*src && i < n)
	{
	*dest = *src;
	dest++;
	src++;
	i++;
	j++;
	}
	*dest = '\0';
	return (dest - j);
}
