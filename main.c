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

	long i = 0;
	while (i++ < 4294967299)
	{	
		ft_printf(">>>|%lx|\n", 4294967296);
		ft_putnbr(i);
		//printf(">>>|%lx|\n", 4294967296);
	}
	//ft_printf("|%#8x|\n", 42);
	//printf("|%#8x|\n", 42);
	printf("%lld", (long long int)42);
	return (0);
}
