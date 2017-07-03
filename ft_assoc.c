#include "ft_printf.h"

void	var_assoc_string(t_var *variable, char *s)
{
	variable->t_val.s = s;
	variable->type = TYPE_STR;
}

void    var_assoc_int(t_var *variable, int i)
{
    variable->t_val.i = i;
    variable->type = TYPE_INT;
}
