#include "ft_printf.h"

void ft_printf_aux(t_var *x)
{
	ft_putstr(x->pre);
	ft_putstr(x->str);
}

int	ft_printf(const char * restrict format, ...)
{
	va_list ap;
	t_var	*x;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (!ft_strncmp("%%", format, 2))
		{
			ft_putchar('%');
			format += 2;
		}
		else if (*format == '%')
		{
			x = ft_init(format);
			x = ft_assign(x, ap);
			x = ft_insert_pre(x);
			x = ft_insert_str(x);
			ft_printf_aux(x);
			format = ft_strchr(format, ft_next_conversion(format));
		}
		else
			ft_putchar(*format);
		format++;	
	}
	va_end(ap);
	return (0);
}
