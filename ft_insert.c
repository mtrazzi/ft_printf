#include "ft_printf.h"

t_var	*ft_insert_pre(t_var *x)
{
	char c;
	
	if (x->f->opt[4] > '0')
	{
		c = (x->f->opt)[4];
		if (c == 'x')
			change_pre(x,"0x");
		else if (c == 'X')
			change_pre(x, "0X");
		else if (c == 'o')
			change_pre(x, "0");
		return (x);
	}
	if (x->f->opt[1] > '0')
		change_pre(x, "+");
	if (x->f->opt[3] > '0')
		change_pre(x, " ");
	return (x);
}

t_var	*ft_insert_str(t_var *x)
{
	if (x->f->type == 'd')
		change_str(x, ft_itoa(x->u->d));
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
	change_mid(x, ft_memset(ft_strnew(n), '0', n));
	while (m + n + str_len + ft_strlen(x->pre) < x->f->min)
		m++;
	change_suf(x, ft_memset(ft_strnew(n), ' ', m));
	return (x);
}

t_var	*ft_insert_mid_suf(t_var *x)
{
	size_t n;
	size_t m;
	char *str1;
	char *str2;

	n = 0;
	m = 0;
	if (x->f->opt[0] > '0')
		return (ft_insert_start(x));
	while (n + ft_strlen(x->str) < x->f->pre)
		n++;
	while (m + n + ft_strlen(x->str) + ft_strlen(x->pre) < x->f->min)
		m++;
	//printf("\n>>>m : %zu", m);
	//printf("\n>>>n : %zu", n);
	//printf("\n>>>str_len : %zu", str_len);
	//printf("\n>>>pre_len : %zu", pre_len);
	//printf("\n>>>x->f->pre : %zu", x->f->pre);
	//printf("\n>>>x->f->min : %d", x->f->min);	
	
	if (!(str1 = ft_memset(ft_strnew(m), ' ', m)))
		exit(EXIT_FAILURE);
	if (!(str2 = ft_memset(ft_strnew(n), '0', n)))
		exit(EXIT_FAILURE);
	change_mid(x, ft_strjoin(str1, str2));
	free(str1);
	free(str2);
	return (x);
}

t_var *ft_insert(t_var *x)
{
	x = ft_insert_pre(x);
	x = ft_insert_str(x);
	x = ft_insert_mid_suf(x);
	return (x);
}
