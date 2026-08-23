#include <unistd.h>
//hi, this code was made by flavides during 42 common core!

void	ft_putstr(char *str)
{
	int  i;

	i = 0;
	while (str[i])
  {
    write(1, &str[i], 1);
		i++;
  }
}
