/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:59:32 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/15 19:07:37 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_var	*ft_assign_d(t_var *x, va_list ap)
{
	if (x->f->type == 'D')
	{
		x->u->ld = va_arg(ap, long);
		x->f->len = 'l';
		x->f->type = 'd';
	}
	if (x->f->len == 0 || x->f->len == -1)
		x->u->d = va_arg(ap, int);
	if (x->f->len == -1 && x->u->d == 0)
	{
		x->f->type = 's';
		x->u->s = "";
	}
	if (x->f->len == 'h')
		x->u->hd = (short)va_arg(ap, int); //promoted
	if (x->f->len == 'H')
		x->u->hhd = (signed char)va_arg(ap, int); //promoted
	if (x->f->len == 'l')
		x->u->ld = va_arg(ap, long);
	if (x->f->len == 'L')
		x->u->lld = va_arg(ap, long long);
	if (x->f->len == 'j')
		x->u->jd = va_arg(ap, intmax_t);
	if (x->f->len == 'z')
		x->u->zd = va_arg(ap, ssize_t);
	return x;
}

t_var	*ft_assign_u(t_var *x, va_list ap)
{
	if (x->f->type == 'O')
	{
		x->u->lu = va_arg(ap, unsigned long);
		x->f->len = 'l';
		x->f->type = 'o';
	}
	else if (x->f->type == 'U')
	{
		//ft_putstr("coucou");
		x->u->ju = va_arg(ap, unsigned long);
		//printf(">>>%U<<<\n", x->u->ju);
		x->f->type = 'u';
		x->f->len = 'j';
	}
	else if (x->f->len == 0)
		x->u->u = va_arg(ap, unsigned int);
	else if (x->f->len == 'h')
		x->u->hu = (unsigned short)va_arg(ap, unsigned int); //promoted
	else if (x->f->len == 'H')
		x->u->hhu = (unsigned char)va_arg(ap, unsigned int); //promoted
	else if (x->f->len == 'l')
		x->u->lu = va_arg(ap, unsigned long);
	else if (x->f->len == 'L')
		x->u->llu = va_arg(ap, unsigned long long);
	else if (x->f->len == 'j')
		x->u->ju = va_arg(ap, uintmax_t);
	else if (x->f->len == 'z')
		x->u->zu = va_arg(ap, size_t);
	return x;
}

t_var	*ft_assign_c(t_var *x, va_list ap)
{
	if (x->f->len == 0)
		x->u->c = va_arg(ap, int);
	if (x->f->len == 'l')
		x->u->lc = va_arg(ap, wint_t);
	return x;
}

t_var	*ft_assign_s(t_var *x, va_list ap)
{
	if (x->f->len == 0)
		x->u->s = va_arg(ap, char *);
	if (x->f->len == 'l')
		x->u->ls = va_arg(ap, wchar_t *);
	return x;
}

t_var	*ft_assign(t_var *x, va_list ap)
{
	if (x->f->type == 'p')
	{
		x->f->type = 'x';
		x->f->len = 'l';
		x->f->opt[4] = 'x';
		x->u->lu = va_arg(ap, unsigned long);
		if (x->u->lu == 0)
			change_pre(x, ft_strdup("0x"));
	}
	else if (ft_strchr("di", x->f->type))
		ft_assign_d(x,ap);
	else if (ft_strchr("oOuUxX", x->f->type))
		ft_assign_u(x,ap);
	else if (x->f->type == 'c')
		ft_assign_c(x,ap);
	else if (x->f->type == 's')
		ft_assign_s(x,ap);
	else if (x->f->type == 'C')
		x->u->lc = va_arg(ap, wint_t);
	else if (x->f->type == 'S')
	{
		x->u->ls = va_arg(ap, wchar_t *);
		if (!x->u->ls)
			x->u->ls = L"(null)";
	}
	return (x);
}
