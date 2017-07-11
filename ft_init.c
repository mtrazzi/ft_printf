#include "ft_printf.h"

t_var	*ft_init(const char *format)
{
	t_var *x;
	t_val *v;

	if (!(x = (t_var *)malloc(sizeof(t_var))))
		exit(EXIT_FAILURE);
	x = ft_parse(format, x);
	if (!(v = (t_val *)malloc(sizeof(t_val))))
		exit(EXIT_FAILURE);
	x->u = v;
	x->mid = ft_strdup("");
	x->pre = ft_strdup("");
	x->str = ft_strdup("");
	x->suf = ft_strdup("");
	return (x);
}
