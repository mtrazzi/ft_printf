#include "ft_printf.h"

int	is_opt(char c)
{
	return (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#');
}

char	*ft_parse_opt_aux(const char *s) //s du type "%-12.4hd"
{
	char *res;

	res = ft_strdup("00000");
	while (is_opt(*(++s)))
	{
		if (*s == '-')
			res[0] = '1';
		if (*s == '+')
			res[1] = '1';
		if (*s == '0')
			res[2] = '1';
		if (*s == ' ')
			res[3] = '1';
		if (*s == '#')
			res[4] = '1';
	}
	return (res);
}

t_var	*ft_parse_opt(const char *s, t_var *x)
{
	char *res;
	t_for *f;
	char c;

	f = (t_for *)malloc(sizeof(t_for));
	res = ft_parse_opt_aux(s);
	if (res[0] > '0' && res[2] > '0')
		res[2] = '0';
	if (res[1] > '0' && res[3] > '0')
		res[3] = '0';
	if ((res[1] > '0' && res[4] > '0')  || (res[3] > '0' && res[4] > '0'))
		exit(EXIT_FAILURE); //comportement non défini avec #+ et #esp
	c = ft_next_conversion(s);
	if (res[4] > '0' && c != 'x' && c != 'X' && c != 'o' && c != 'O')
		exit(EXIT_FAILURE);
	f->opt = res;
	x->f = f;
	return (x);
}
