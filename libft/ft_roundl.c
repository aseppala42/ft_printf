#include "libft.h"

long double	ft_roundl(long double x)
{
	if (ft_fabsl(x) - ft_imaxabs(x) < 0.5)
		return ((intmax_t)x);
	return (x < 0 ? ft_floorl(x) : ft_ceill(x));
}
