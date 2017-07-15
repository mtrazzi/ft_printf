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

	setlocale(LC_ALL, "");
	ft_printf("%4S\n", NULL);
	printf("%4S\n", NULL);
	return (0);
}
