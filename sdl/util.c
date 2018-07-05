char		*digit_to_str(int i)
{
  static char	str[2];

  str[0] = '0' + i;
  return str;
}
