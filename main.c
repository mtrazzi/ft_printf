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

	ft_printf("%-3.5d\n", 42);
	ft_printf("%-.5d\n", 42);
	ft_printf("%12.5d\n", 42);
	return (0);
}
