/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:00:36 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/14 14:51:23 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	change_pre(t_var *x, char *str)
{
	if (!str)
		exit(EXIT_FAILURE);
	free(x->pre);
	//if (!(x->pre = ft_strdup(str)))
	//	exit(EXIT_FAILURE);
	x->pre = str;
}

void	change_str(t_var *x, char *str)
{
	if (!str && (x->f->type == 's' && x->u->s == NULL))
		change_str(x, "(null)");
	if (!str)
		exit(EXIT_FAILURE);
	free(x->str);
	//if (!(x->str = ft_strdup(str)))
	//	exit(EXIT_FAILURE);
	x->str = str;
}

void	change_mid(t_var *x, char *str)
{
	if (!str)
		exit(EXIT_FAILURE);
	free(x->mid);
	//if (!(x->mid = ft_strdup(str)))
	//	exit(EXIT_FAILURE);
	x->mid = str;
}

void	change_suf(t_var *x, char *str)
{
	if (!str)
		exit(EXIT_FAILURE);
	free(x->suf);
	//if (!(x->suf = ft_strdup(str)))
	//	exit(EXIT_FAILURE);
	x->suf = str;
}
