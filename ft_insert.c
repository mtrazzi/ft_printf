#include "ft_printf.h"

t_var	*ft_insert_pre(t_var *x)
{
	char c;
	
	if (x->f->opt[4] > '0')
	{
		c = (x->f->opt)[4];
		if (c == 'x')
			x->pre = "0x";
		else if (c == 'X')
			x->pre = "0X";
		else if (c == 'o')
			x->pre = "0";
		return (x);
	}
	if (x->f->opt[1] > '0')
		x->pre = "+";
	if (x->f->opt[3] > '0')
		x->pre = " ";
	else
		x->pre = "";
	return (x);
}

t_var	*ft_insert_str(t_var *x)
{
	if (x->f->type == 'd')
		x->str = ft_itoa(x->u->d);
	return (x);
}

t_var	*ft_insert_start(t_var *x)
{
	size_t	n; //taille de la str a mettre dans mid (nb de 0)
	size_t	pre_len;
	size_t  str_len;
	size_t	m; //taille de la str a mettre dans suf (nb d'esp)

	n = 0;
	m = 0;
	pre_len = (x->f->type == 'o' ? ft_strlen(x->pre) : 0);
	str_len = ft_strlen(x->str);
	while (n + str_len + pre_len < x->f->pre)
		n++;
	x->mid = ft_memset(ft_strnew(n), '0', n);
	while (m + n + str_len + ft_strlen(x->pre) < x->f->min)
		m++;
	x->suf = ft_memset(ft_strnew(n), ' ', m);
	return (x);
}

t_var	*ft_insert_mid_suf(t_var *x)
{
	size_t n;
	size_t pre_len;
	size_t str_len;
	size_t m;

	n = 0;
	m = 0;
	if (x->f->opt[0] > '0')
		return (ft_insert_start(x));
	pre_len = ft_strlen(x->pre);
	str_len = ft_strlen(x->str);
	while (n + str_len < x->f->pre)
		n++;
	while (m + n + str_len + pre_len < x->f->min)
		m++;
	//printf("\n>>>m : %zu", m);
	//printf("\n>>>n : %zu", n);
	//printf("\n>>>str_len : %zu", str_len);
	//printf("\n>>>pre_len : %zu", pre_len);
	//printf("\n>>>x->f->pre : %d", x->f->pre);
	//printf("\n>>>x->f->min : %d", x->f->min);	
	x->mid = ft_strjoin(ft_memset(ft_strnew(m), ' ', m), ft_memset(ft_strnew(n), '0', n));
	return (x);
}

t_var *ft_insert(t_var *x)
{
	x = ft_insert_pre(x);
	x = ft_insert_str(x);
	x = ft_insert_mid_suf(x);
	return (x);
}
