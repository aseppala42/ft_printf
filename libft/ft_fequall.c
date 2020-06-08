#include "libft.h"

int	ft_fequall(long double x, long double y)
{
	return (ft_fabsl(x - y) <= EPSILON * ft_fmaxl(1.0f, ft_fmaxl(ft_fabsl(x), ft_fabsl(y))));
}
