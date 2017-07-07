/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:10:13 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/06/26 16:50:11 by mtrazzi          ###   ########.fr       */
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

typedef struct	s_for
{
	char *opt; //to free
	int min;
	int pre;
	char len; //L pour ll et H pour hh
	char type;
}		t_for;

typedef struct	s_var
{
	union		u_val
	{
		int			i;
		short		h;
		long		l;
		char		c;
		char		*s;
		wint_t		wi;
		wchar_t		*wc;
		void		*p;
	}			t_val;
	t_for		*f;
}		t_var;


enum
{
	TYPE_INT, TYPE_SHORT, TYPE_LONG, TYPE_CHAR, TYPE_STR, TYPE_WINT, TYPE_WSTR, TYPE_PTR
};

t_var	*ft_parse_opt(const char *s, t_var *x);
t_var	*ft_parse(const char *s, t_var *x);
char	ft_next_conversion(const char *str);
void	var_assoc_string(t_var *variable, char *s);
int	ft_printf(const char *format, ...);
void var_print(t_var *variable);
int	is_opt(char c);


#endif
