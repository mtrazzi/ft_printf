#include "ft_printf.h"

void ft_printf_aux(t_var *x)
{
	//ft_putstr("mid>>>");
	//ft_putstr(x->mid);
	//ft_putstr("<<<\npre>>>");
	//ft_putstr(x->pre);
	//ft_putstr("<<<\nstr>>>");
	//ft_putstr(x->str);
	//ft_putstr("<<<\nsuf>>>");
	//ft_putstr(x->suf);
	//ft_putstr("<<<\n|");
	ft_putstr(x->mid);
	ft_putstr(x->pre);
	ft_putstr(x->str);
	ft_putstr(x->suf);
}

int	ft_printf(const char * restrict format, ...)
{
	va_list ap;
	t_var	*x;
	size_t  ret;

	ret = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		//ft_putchar(ft_next_conversion(format + 1));
		if (!ft_strncmp("%%", format, 2))
		{
			//ft_putstr("coucou1\n");
			ft_putchar('%');
			ret++;
			format += 1;
		}
		else if (*format == '%' && ft_next_conversion(format + 1))
		{
			//ft_putstr("coucou2\n");
			x = ft_init(format);
			x = ft_assign(x, ap);
			x = ft_conv_d(x);
			x = ft_insert(x);
			ret += ft_strlen(x->mid) + ft_strlen(x->pre) + ft_strlen(x->str) + ft_strlen(x->suf);
			ft_printf_aux(x);
			format = ft_strchr(format + 1, ft_next_conversion(format + 1));
			ft_free_all(x);
		}
		else 
		{
			//ft_putstr("coucou3\n");
			ret++;
			ft_putchar(*format);
		}
		format++;
	}
	va_end(ap);
	return (ret);
}
