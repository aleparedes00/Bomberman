int		my_getnbr(char *str)
{
  int nb;
  int neg;
  
  nb = 0;
  neg = 0;
  while (*str == '+' || *str == '-')
    {
      if (*str == '-')
	neg++;
      str++;
    }
  if (*str >= '0' && *str <= '9')
    {
      nb += (*str  - 48);
      while (*(str + 1) != '\0' && *(str + 1) >= '0' && *(str + 1) <= '9')
	{
	  nb = nb * 10;
	  str++;
	  nb += *str - '0';
	}
    }
  if (neg % 2 != 0)
    nb = -nb;
  return (nb);
}
