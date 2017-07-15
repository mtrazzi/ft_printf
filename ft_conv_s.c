/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:24:18 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/15 21:57:12 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_var	*ft_conv_s(t_var *x)
{
	if (x->f->len == -1)
		return (x);
	else if (x->u->s == NULL)
	{
		x->u->s = "(null)";
		return (ft_conv_s(x));
	}
	else if (x->f->pre == 0)
		change_str(x, ft_strdup(x->u->s));
	else
		change_str(x, ft_strndup(x->u->s, x->f->pre));
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
