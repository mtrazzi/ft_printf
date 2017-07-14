/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:00:59 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/14 16:34:15 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_final_print(char *s1, char *s2, char *s3, char *s4)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
	ft_putstr(s4);
}

char *end_format(const char *str)
{
	char *s;
	size_t i;

	i = 0;
	s = (char *)end_op(str);
	while (ft_isdigit(s[i]))
		i++;
	if (str[i] == '.')
	{
		while (ft_isdigit(s[i + 1]))
			i++;
		i--;
	}
	while (ft_strchr("hljz", s[i]))
		i++;
	return (s + i);	
}

void ft_printf_aux(t_var *x)
{
	/*ft_putstr("mid>>>");
	ft_putstr(x->mid);
	ft_putstr("<<<\npre>>>");
	ft_putstr(x->pre);
	ft_putstr("<<<\nstr>>>");
	ft_putstr(x->str);
	ft_putstr("<<<\nsuf>>>");
	ft_putstr(x->suf);
	ft_putstr("<<<\n|");
	ft_putchar(x->f->type);
	ft_putchar(x->f->len);
	ft_putchar('\n');*/
	if (x->pre[0] == '-' && x->mid[0] == '0')
	{
		ft_final_print(x->pre, x->mid, x->str, x->suf);
		return ;
	}
	if (x->f->type == 'c' && x->u->c == 0)
	{
		ft_putstr(x->mid);
		ft_putchar(0);
		ft_putstr(x->suf);
		return;
	}
	if (!ft_strncmp(x->pre, "+", 1) && !ft_strncmp(x->mid, " ", 1))
	{
		x->mid = ft_insert_plus(x->mid);
		change_pre(x, ft_strdup(" "));
	}
	if (x->f->opt[2] > '0')
		ft_final_print(x->pre, x->mid, x->str, x->suf);
	else if ((!ft_strncmp(x->pre, "+", 1) || !ft_strncmp(x->pre, " ", 1)) && x->f->type == 'd')
		ft_final_print(x->pre, x->mid, x->str, x->suf);
	else
		ft_final_print(x->mid, x->pre, x->str, x->suf);
}

int	ft_printf(const char * restrict format, ...)
{
	va_list ap;
	t_var	*x;
	size_t  ret;

	ret = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		//ft_putchar(ft_next_conversion(format + 1));
		if (!ft_strncmp("%%", format, 2))
		{
			//ft_putstr("coucou1\n");
			ft_putchar('%');
			ret++;
			format += 2;
		}
		else if (*format == '%' && ft_next_conversion(format + 1))
		{
			//ft_putstr("coucou2\n");
			x = ft_init(format);
			x = ft_assign(x, ap);
			x = ft_conv_d(x);
			x = ft_insert(x);
			ft_printf_aux(x);
			ret += ft_strlen(x->mid) + ft_strlen(x->pre) + ft_strlen(x->str) + ft_strlen(x->suf);
			format = ft_strchr(format + 1, ft_next_conversion(format + 1)) + 1;
			ft_free_all(x);
		}
		else if (*format == '%' && *(format + 1))
		{
			format = end_format(format + 1);
			ft_putchar(*format);
		}
		else if (*format == '%')
			format++;
		else
		{
			//ft_putstr("coucou3\n");
			ret++;
			ft_putchar(*format);
			format++;
		}
	}
	va_end(ap);
	return (ret);
}
