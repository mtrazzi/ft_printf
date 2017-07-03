#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <wchar.h>

void	var_print(t_var *variable)
{
	switch(variable->type)
	{
		case TYPE_STR:
		printf("%s\n", variable->t_val.s);
		break;
		default:
		printf("Unknown type\n");
		break;
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	ft_printf(">>>%s<<<", av[1]);
	return (0);
}
