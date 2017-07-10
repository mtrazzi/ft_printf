#include "ft_printf.h"

t_var	*ft_init(const char *format)
{
	t_var *x;
	t_val *v;

	x = (t_var *)malloc(sizeof(t_var));
	x = ft_parse(format, x);
	v = (t_val *)malloc(sizeof(t_val));
	x->u = v;
	x->pre = "";
	x->str = "";
	return (x);
}
