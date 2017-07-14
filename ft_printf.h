/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:10:13 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/14 16:12:46 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <stdint.h>
# include <wchar.h>
# include <locale.h>
# include <limits.h>

typedef struct	s_for //to free
{
	char *opt; //to free : ordre : -+0' '#
	size_t	min;
	size_t	pre;
	char len; //L pour ll et H pour hh
	char type;
}		t_for;

typedef union		u_val
{
	int			d; //for i also
	char		hhd;
	short		hd;
	long		ld; //works for D
	long long	lld;
	intmax_t	jd;
	ssize_t		zd;
	unsigned int	u;
	unsigned char hhu;
	unsigned short hu;
	unsigned long  lu; //or U
	unsigned long long llu;
	uintmax_t ju;
	size_t	  zu;
	char		c;
	char		*s;
	wint_t		lc; //or C
	wchar_t		*ls; //or S
	void		*p;
}					t_val;

typedef struct	s_var
{
	t_val		*u;
	t_for		*f;
	char		*pre; //le prefixe simple du type +, -, O, oX, OX
	char		*mid; //le remplissage de 0 ou ' '
	char		*str; //le nb essentiellement
	char		*suf; //ce qui vient apres notre str dans le cas du -
}		t_var;

const char *end_op(const char *s);
t_var	*ft_parse_opt(const char *s, t_var *x);
t_var	*ft_parse(const char *s, t_var *x);
char	ft_next_conversion(const char *str);
void	var_assoc_string(t_var *variable, char *s);
int	ft_printf(const char *format, ...);
void var_print(t_var *variable);
int	is_opt(char c);
t_var *ft_init(const char *format);
t_var *ft_assign(t_var *, va_list ap);
t_var *ft_insert(t_var *x);
char	*ft_itoa_base(unsigned long long n, char *base);
t_var	*ft_conv_d(t_var *x);
t_var	*ft_conv_s(t_var *x);
t_var	*ft_conv_c(t_var *x);
t_var	*ft_conv_d_aux_bis(t_var *);
t_var	*ft_conv_d_aux(t_var *x, char *str);
void	change_pre(t_var *x, char *str);
void	change_str(t_var *x, char *str);
void	change_mid(t_var *x, char *str);
void	change_suf(t_var *x, char *str);
void	ft_free_all(t_var *x);
int		ft_is_null_u(t_var *x);
char	*ft_strndup(const char *s, size_t n);
char	*ft_insert_plus(char *str);
#endif
