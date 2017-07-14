/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:00:47 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/14 15:12:59 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_var	*ft_insert_pre(t_var *x)
{
	char c;
	
	if (x->f->opt[4] != '0' && !ft_is_null_u(x))
	{
		c = (x->f->opt)[4];
		if (c == 'x')
			change_pre(x, ft_strdup("0x"));
		else if (c == 'X')
			change_pre(x, ft_strdup("0X"));
		else if (c == 'o')
			change_pre(x, ft_strdup("0"));
		return (x);
	}
	if (x->f->opt[1] > '0')
		change_pre(x, ft_strdup("+"));
	if (x->f->opt[3] > '0' && !(x->f->type == '%'))
		change_pre(x, ft_strdup(" "));
	return (x);
}

t_var	*ft_insert_str(t_var *x)
{
	if (ft_strchr("di", x->f->type))
		ft_conv_d_aux_bis(x);
	if (ft_strchr("u", x->f->type))
		ft_conv_d_aux(x, "0123456789");
	if (ft_strchr("oxX", x->f->type))
		ft_conv_d(x);
	if (x->f->type == 's')
		ft_conv_s(x);
	if (x->f->type == '%')
		change_str(x, ft_strdup("%"));
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
	if (x->f->type == 's')
		n = 0;
	change_mid(x, ft_memset(ft_strnew(n), '0', n));
	while (m + n + str_len + ft_strlen(x->pre) < x->f->min)
		m++;
	change_suf(x, ft_memset(ft_strnew(m), ' ', m));
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
	if ((!ft_strncmp(x->pre, "+", 1) || !ft_strncmp(x->pre, " ", 1)) && ft_atoi(x->str) < 0)
		change_pre(x, ft_strdup(""));
	if (x->f->opt[0] > '0')
		return (ft_insert_start(x));
	if ((x->f->pre != 0 || x->f->opt[2] > '0') && ft_atoi(x->str) < 0 && (ft_strchr("di", x->f->type)))
	{
		change_str(x, ft_strdup(x->str + 1));
		change_pre(x,  ft_strdup("-"));
	}
	if (x->f->pre != 0 && x->f->opt[2] > '0')
		x->f->opt[2] = '0';
	while (n + (x->f->type == 'o' ? ft_strlen(x->pre) : 0) + ft_strlen(x->str) - (x->str[0] == '-') < x->f->pre)
		n++;
	if (x->f->type == 's')
		n = 0;
	while (m + n + ft_strlen(x->str) + ft_strlen(x->pre) < x->f->min)
		m++;
//	printf("\n>>>m : %zu", m);
//	printf("\n>>>n : %zu", n);
//	printf("\n>>>str_len : %zu", ft_strlen(x->str));
//	printf("\n>>>pre_len : %zu", ft_strlen(x->pre));
//	printf(">>>%s<<<\n", x->pre);
//	printf("\n>>>x->f->pre : %zu", x->f->pre);
//	printf("\n>>>x->f->min : %zu", x->f->min);	
	
	if (!(str1 = ft_memset(ft_strnew(m), (x->f->opt[2] > '0' ? '0' : ' '), m)))
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
	char *str;
	//if (x->f->type == 'c')
	//	ft_conv_c(x);
	if (x->f->type == 's' && !(x->str))
		return (x);
	if (x->f->type == 'c' && (x->u->c == 0))
	{
		change_str(x, ft_strdup(" "));
		x->f->type = 'd';
		x->f->len = 0;
		x->u->d = 1;
		x->f->pre = 0;
		ft_insert_str(x);
		ft_insert_mid_suf(x);
		x->f->type = 'c';
		x->u->c = 0;
		return (x);
	}
	if (x->f->type == 'c')
	{
		str = ft_strnew(1);
		str[0] = x->u->c;
		x->f->type = 's';
		x->u->s = str;
	}
	x = ft_insert_pre(x);
	x = ft_insert_str(x);
	x = ft_insert_mid_suf(x);
	return (x);
}
