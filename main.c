#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <wchar.h>
#include <locale.h>

int main(int ac, char **av)
{
	(void)ac;

	ft_printf("coucou !\n%s\nJe suis a %d\n", "C'est bob", 23234325235);
}
