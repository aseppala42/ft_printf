#include "libft.h"

int	ft_fequal(double x, double y)
{
	return (ft_fabs(x - y) <= EPSILON * ft_fmax(1.0f, ft_fmax(ft_fabs(x), ft_fabs(y))));
}
