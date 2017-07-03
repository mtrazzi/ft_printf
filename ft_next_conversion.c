#include "ft_printf.h"

int		ft_is_conversion(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D')
		return (1);
	else if (c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
		return (1);
	else
		return (c == 'x' || c == 'X' || c == 'c' || c == 'C');
}

char	ft_next_conversion(char *str)
{
	int i;

	i = 0;
	while (str[i] && !(ft_is_conversion(str[i])))
		i++;
	return (str[i]);
}
