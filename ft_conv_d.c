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

t_var	*ft_conv_d(t_var *x)
{
	if (x->f->type == 'o')
		x->str = ft_itoa_base(x->u->u, "01234567");
	return (x);
}
