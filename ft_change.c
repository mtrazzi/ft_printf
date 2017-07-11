#include "ft_printf.h"

void	change_pre(t_var *x, char *str)
{
	if (!str)
		exit(EXIT_FAILURE);
	free(x->pre);
	if (!(x->pre = ft_strdup(str)))
		exit(EXIT_FAILURE);
}

void	change_str(t_var *x, char *str)
{
	if (!str)
		exit(EXIT_FAILURE);
	free(x->str);
	if (!(x->str = ft_strdup(str)))
		exit(EXIT_FAILURE);
}

void	change_mid(t_var *x, char *str)
{
	if (!str)
		exit(EXIT_FAILURE);
	free(x->mid);
	if (!(x->mid = ft_strdup(str)))
		exit(EXIT_FAILURE);
}

void	change_suf(t_var *x, char *str)
{
	if (!str)
		exit(EXIT_FAILURE);
	free(x->suf);
	if (!(x->suf = ft_strdup(str)))
		exit(EXIT_FAILURE);
}
