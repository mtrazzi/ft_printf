/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:00:52 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/12 17:23:29 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*end_op(const char *s)
{
	int i;

	i = 0;
	while (is_opt(s[i]) == 1)
		i++;
	return (s + i);
}

t_var		*ft_parse_min(const char *s, t_var *x)
{
	x->f->min = ft_atoi(end_op(s + 1));
	return (x);
}

t_var		*ft_parse_pre(const char *s, t_var *x)
{
	const char *str;
	int i;

	i = 0;
	str = end_op(s + 1);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		x->f->pre = ft_atoi(str + i + 1);
		if (x->f->pre == 0)
			x->f->len = -1;
	}
	else
		x->f->pre = 0; //défault
	return (x);
}

t_var		*ft_parse_type(const char *s, t_var *x)
{
	x->f->type = ft_next_conversion(s + 1);
	return (x);
}

char		ft_len_spe(const char *str)
{
	if (!(ft_strncmp(str, "hh", 2)) || !(ft_strncmp(str, "ll", 2)))
		return (ft_toupper(*str));
	else if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
		return (*str);
	else
		return (0);
}

t_var		*ft_parse(const char*s, t_var *x)
{
	int i;

	i = 1;
	x = ft_parse_type(s, ft_parse_pre(s, ft_parse_min(s, ft_parse_opt(s, x))));
	while (is_opt(s[i]))
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
		while (ft_isdigit(s[++i])) {}
	if (x->f->len != -1)
		x->f->len = ft_len_spe(s + i);
	return (x);
}
