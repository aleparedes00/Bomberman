void	my_putchar(char c);

void	my_putstrwnl(char *str)
{
  while (*str != '\0'){
    my_putchar(*str);
    str++;
  }
  my_putchar('\n');
}
