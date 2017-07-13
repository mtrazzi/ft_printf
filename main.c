#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int x;

	x = 32768;
	ft_printf("%hd\n", x);
//	x = (short)x;
//	ft_printf("%hd\n", x);
//	x = (long long)x;
//	ft_printf("%hd\n", x);
	
	return (0);
}
