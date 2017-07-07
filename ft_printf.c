#include "ft_printf.h"

int	ft_printf(const char * restrict format, ...)
{
	va_list ap;
	t_var	*x;
	int ret;

	x = (t_var *)malloc(sizeof(t_var));
	va_start(ap, format);
	ret = 0;
	while (*format != '\0')
	{
		if (!ft_strncmp("%%", format, 2))
		{
			ft_putchar('%');
			format += 2;
		}
		else if (*format == '%')
		{
			x = ft_parse(format, x);
			ft_putstr(x->f->opt);
			ft_putchar('\n');
			ft_putnbr(x->f->min);
			ft_putchar('\n');
			ft_putnbr(x->f->pre);
			ft_putchar('\n');
			ft_putchar(x->f->len);
			ft_putchar('\n');
			ft_putchar(x->f->type);
			format = ft_strchr(format, ft_next_conversion(format));
		}
		else
			ft_putchar(*format);
		format++;	
	}
	va_end(ap);
	return (0);
}
