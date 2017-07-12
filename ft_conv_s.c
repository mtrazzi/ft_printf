#include "ft_printf.h"

t_var	*ft_conv_s(t_var *x)
{
	if (x->f->len == -1)
		return (x);
	else if (x->u->s == NULL)
		change_str(x, "(null)");
	else if (x->f->pre == 0)
		change_str(x, x->u->s);
	else
		change_str(x, ft_strndup(x->u->s, x->f->pre));
	return (x);
}

t_var	*ft_conv_c(t_var *x)
{
	//char *str;

	//if (x->u->c == 0)
	//{
	//	ft_putstr("\ntest%^@%&#^%@*!^(!#^&&*^");
	//	change_str(x, NULL);
	//	x->f->type = 's';
	//	return (x);
	//}
	//str = ft_strnew(1);
	//str[0] = x->u->c;

	//x->f->type = 's';
	return (x);
}
