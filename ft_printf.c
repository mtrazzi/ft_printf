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
			x = ft_insert(x, va_arg(ap, x->type)); //problem because x->type can have any type
			ft_putstr(ft_convert(x));
		}
		format++;	
	}
	va_end(ap);
	return (0);
}
