#include "ft_printf.h"

size_t	ft_size_C(t_var *x)
{
	int n;
	size_t res;

	n = ft_count_bits(x->u->lc);
	if (n <= 7)
		res = 1;
	else if (n <= 11)
		res = 2;
	else if (n <= 16)
		res = 3;
	else
		res = 4;
	return (res);
}

void	ft_print_C_minus(t_var *x)
{
	size_t nb_bytes;
	size_t i;

	nb_bytes = ft_size_C(x);
	i = nb_bytes;
	ft_putwchar_t(x->u->lc);
	while (i < x->f->min)
	{
		ft_putchar(' ');
		i++;
	}
}

void	ft_print_C(t_var *x)
{
	size_t nb_bytes;
	size_t i;

	nb_bytes = ft_size_C(x);
	if (x->f->opt[0] > '0')
	{
		ft_print_C_minus(x);
		return;
	}
	i = 0;
	while (i + nb_bytes < x->f->min)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putwchar_t(x->u->lc);
}	
