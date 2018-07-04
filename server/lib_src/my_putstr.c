void	my_putchar(char c);

void	my_putstr(char *str)
{
  while (*str != '\0'){
    my_putchar(*str);
    str++;
  }
}
