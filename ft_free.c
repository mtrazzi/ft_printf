#include "ft_printf.h"

void	ft_free_all(t_var *x)
{
	free(x->f->opt);
	free(x->f);
	free(x->u);
	free(x->mid);
	free(x->pre);
	free(x->str);
	free(x->suf);
	free(x);
}
