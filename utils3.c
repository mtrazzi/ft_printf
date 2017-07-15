/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 19:39:39 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/15 19:53:55 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

int		ft_atoi(const char *nptr)
{
	int					s;
	int					i;
	unsigned long long	nb;

	i = 0;
	s = 1;
	nb = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || \
nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
		s = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (48 <= nptr[i] && nptr[i] <= 57)
	{
		nb = 10 * nb + nptr[i] - 48;
		i++;
	}
	if (nb > 9223372036854775807 && s == -1)
		return (0);
	if (nb > 9223372036854775807 && s == 1)
		return (-1);
	return ((int)(s * nb));
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*answer;

	i = 0;
	answer = (char*)s;
	while (i < n)
	{
		answer[i] = '\0';
		i++;
	}
	s = (void *)answer;
}

int		ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
