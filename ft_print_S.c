#include "ft_printf.h"

size_t	ft_size_C_i(t_var *x, size_t i)
{
	int n;
	size_t res;

	n = ft_count_bits(x->u->ls[i]);
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

size_t	ft_size_S(t_var *x)
{
	size_t 	i;
	size_t	sum;
	wchar_t *s;

	i = 0;
	sum = 0;
	s = x->u->ls;
	while (s[i])
	{
		sum += ft_size_C_i(x, i);
		i++;
	}
	return (sum);
}

void	ft_print_S_minus(t_var *x)
{
	size_t nb_bytes;
	size_t i;

	nb_bytes = ft_size_S(x);
	i = nb_bytes;
	ft_putstr_uni(x->u->ls);
	while (i < x->f->min)
	{
		ft_putchar(' ');
		i++;
	}
}

void	ft_print_S(t_var *x)
{
	size_t nb_bytes;
	size_t i;

	nb_bytes = ft_size_S(x);
	if (x->f->opt[0] > '0')
	{
		ft_print_S_minus(x);
		return;
	}
	i = 0;
	while (i + nb_bytes < x->f->min)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putstr_uni(x->u->ls);
}	
