char	*my_strncpy(char *dest, char *src, int n)
{
  int i;
  int j;
  i = 0;
  j = 0;
  
  while (*src != '\0' && i < n)
    {
      *dest = *src;
      src++;
      dest++;
      i++;
      j++;
    }
  src--;
  if (i < n)
    *dest = '\0';
  return (dest - j);
}
