#include "ft_printf.h"

int	ft_printf(const char * restrict format, ...)
{
	va_list ap;
	t_var	*x;

	x = (t_var *)malloc(sizeof(t_var));
	va_start(ap, format);
	while (*format != '\0')
	{
		if (!(ft_strncmp(format, "%s", 2)))
		{
			var_assoc_string(x, va_arg(ap, char *));
			var_print(x);
			format = ft_strchr(format, 's');
		}
		else
			ft_putchar(*format);
		format++;
		
	}
	va_end(ap);
	return (0);
}
