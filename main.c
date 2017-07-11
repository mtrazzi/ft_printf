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

	ft_printf("|%#8o|\n", 42);
	printf("|%#8o|\n", 42);
	return (0);
}
