/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 19:38:52 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/16 18:42:50 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	if (n < 10 && n >= 0)
		ft_putchar('0' + n);
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar('0' + n % 10);
	}
}

void	ft_putstr(char const *s)
{
	int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	*ft_strdup(const char *s)
{
	char	*temp;
	int		i;

	i = 0;
	if ((temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		exit(EXIT_FAILURE);
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*temp;
	size_t	i;

	i = 0;
	if ((temp = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		exit(EXIT_FAILURE);
	while (i < n && s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strnew(size_t size)
{
	char *tmp;

	if ((tmp = (char *)ft_memalloc(size + 1)) == NULL)
		exit(EXIT_FAILURE);
	return (tmp);
}
