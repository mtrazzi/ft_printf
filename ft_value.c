/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:00:10 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/16 19:37:57 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_null_u(t_var *x)
{
	t_val	*a;
	char	c;

	c = x->f->len;
	a = x->u;
	if (c == 0 && a->u == 0)
		return (1);
	if (c == 'l' && a->lu == 0)
		return (1);
	if (c == 'L' && a->llu == 0)
		return (1);
	if (c == 'h' && a->hu == 0)
		return (1);
	if (c == 'H' && a->hhu == 0)
		return (1);
	if (c == 'j' && a->ju == 0)
		return (1);
	if (c == 'z' && a->zu == 0)
		return (1);
	if (c == -1 && !a->u && !a->lu && !a->llu && !a->hu && !a->hhu && !a->ju && !a->zu)
		return (1);
	return (0);
}
