#include "ft_printf.h"

static size_t	num_dig_base(unsigned long long n, char *base)
{
	size_t m;
	size_t count;

	m = ft_strlen(base);
	count = 1;
	while (n >= m)
	{
		n /= m;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char *tmp;
	int	len;

	len = num_dig_base(n, base);
	if (!(tmp = ft_strnew(sizeof(char) * len)))
		return (NULL);
	while (--len >= 0)
	{
		tmp[len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (tmp);
}

t_var	*ft_conv_d_aux(t_var *x, char *str)
{
	if (x->f->len == 'l')
		change_str(x, ft_itoa_base(x->u->lu, str));
	else if (x->f->len == 'L')
		change_str(x, ft_itoa_base(x->u->llu, str));
	else if (x->f->len == 'h')
		change_str(x, ft_itoa_base(x->u->hu, str));
	else if (x->f->len == 'H')
		change_str(x, ft_itoa_base(x->u->hhu, str));
	else if (x->f->len == 'j')
		change_str(x, ft_itoa_base(x->u->ju, str));
	else
		change_str(x, ft_itoa_base(x->u->u, str));
	return (x);
}

t_var	*ft_conv_d(t_var *x)
{

	if (x->f->type == 'o')
		ft_conv_d_aux(x, "01234567");
	if (x->f->type == 'x')
		ft_conv_d_aux(x, "0123456789abcdef");
	if (x->f->type == 'X')
		ft_conv_d_aux(x, "0123456789ABCDEF");
	return (x);
}
