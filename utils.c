/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:01:05 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/13 20:53:17 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ans;

	ans = (char *)s;
	i = 0;
	while (ans[i] && ans[i] != c)
		i++;
	if (ans[i] == c)
		return (ans + i);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && i < n - 1)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

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
		return (NULL);
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
		return (NULL);
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
		return (NULL);
	return (tmp);
}

int		ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_atoi(const char *nptr)
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

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}


static	size_t			num_dig(long long n)
{
	size_t m;

	m = 1;
	while (n > 9)
	{
		n /= 10;
		m++;
	}
	return (m);
}

static char				*ft_itoa_aux(long long n, char *s, int len, int i)
{
	while (--len >= 0)
	{
		s[len] = '0' + n % 10;
		n /= 10;
	}
	return (s - i);
}

char					*ft_itoa(long long n)
{
	char *tmp;

	if (n == LLONG_MIN)
	{
		if ((tmp = ft_strnew(sizeof(char) * 20)) == NULL)
			return (NULL);
		return (ft_strncpy(tmp, "-9223372036854775808", 20));
	}
	if (n < 0)
	{
		if ((tmp = ft_strnew(num_dig(-n) + 1)) == NULL)
			return (NULL);
		tmp[0] = '-';
		return (ft_itoa_aux(-n, tmp + 1, num_dig(-n), 1));
	}
	if ((tmp = ft_strnew(sizeof(char) * num_dig(n))) == NULL)
		return (NULL);
	return (ft_itoa_aux(n, tmp, num_dig(n), 0));
}

static	size_t			num_dig_u(unsigned long long n)
{
	size_t m;

	m = 1;
	while (n > 9)
	{
		n /= 10;
		m++;
	}
	return (m);
}

static char				*ft_itoa_aux_u(unsigned long long n, char *s, int len, int i)
{
	while (--len >= 0)
	{
		s[len] = '0' + n % 10;
		n /= 10;
	}
	return (s - i);
}

char					*ft_itoa_u(unsigned long long n)
{
	char *tmp;

	if ((tmp = ft_strnew(sizeof(char) * num_dig_u(n))) == NULL)
		return (NULL);
	return (ft_itoa_aux_u(n, tmp, num_dig(n), 0));
}

void	*ft_memalloc(size_t size)
{
	char	*ans;

	if ((ans = (char *)malloc(size)) == 0)
		return (NULL);
	ft_bzero(ans, size);
	return (ans);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned int	i;
	char			*answer;
	unsigned char	c_p;

	i = 0;
	c_p = (unsigned char)c;
	answer = (char *)str;
	while (i < n)
	{
		answer[i] = c;
		i++;
	}
	return (answer);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	return (ft_strcat(ft_strcat(dst, s1), s2));
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_insert_plus(char *str)
{
	char *dest;
	size_t	i;

	i = 0;
	dest = ft_strdup(str);
	while (str[i] == ' ')
		i++;
	dest[i - 1] = '+';
	return (dest);
}
