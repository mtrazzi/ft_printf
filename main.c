#include "ft_printf.h"

int main()
{
	setlocale(LC_ALL, "");
	ft_printf("{%.u, %.0u}\n", 0, 0);
	printf("{%.u, %.0u}\n", 0, 0);
	return (0);
}
