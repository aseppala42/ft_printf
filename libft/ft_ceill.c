#include "libft.h"

long double	ft_ceill(long double x)
{
	return ((intmax_t)x < x ? (intmax_t)(++x) : (intmax_t)x);
}
