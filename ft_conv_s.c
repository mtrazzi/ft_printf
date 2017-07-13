/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 14:24:18 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/13 14:24:21 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_var	*ft_conv_s(t_var *x)
{
	if (x->f->len == -1)
		return (x);
	else if (x->u->s == NULL)
		change_str(x, "(null)");
	else if (x->f->pre == 0)
		change_str(x, x->u->s);
	else
		change_str(x, ft_strndup(x->u->s, x->f->pre));
	return (x);
}
