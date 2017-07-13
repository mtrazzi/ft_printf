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

	uintmax_t x = UINT_MAX;
	ft_printf("%U\n", ");
	printf("%U\n", x);

	return (0);
}
