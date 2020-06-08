#include "libft.h"

double	ft_floor(double x)
{
	return ((intmax_t)x > x ? (intmax_t)(--x) : (intmax_t)x);
}
