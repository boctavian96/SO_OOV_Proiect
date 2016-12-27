int arg_size(char **argumente)
{
  int size = 0;
  while(argumente[++size] != '\0');
  return size;
}
