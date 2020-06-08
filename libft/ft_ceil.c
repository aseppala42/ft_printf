#include "libft.h"

double	ft_ceil(double x)
{
	return ((intmax_t)x < x ? (intmax_t)(++x) : (intmax_t)x);
}
