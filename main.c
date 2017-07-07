#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <wchar.h>

int main(int ac, char **av)
{
	(void)ac;
	
	ft_printf("%#04llo");
	return (0);
}
