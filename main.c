#include "ft_printf.h"

int main()
{
	setlocale(LC_ALL, "");
	ft_printf("%.lu, %.0u\n", 0L, 0);
	printf("%.lu, %.0u\n", 0L, 0);
	return (0);
}
