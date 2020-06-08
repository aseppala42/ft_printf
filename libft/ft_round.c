#include "libft.h"

double	ft_round(double x)
{
	if (ft_fabs(x) - ft_imaxabs(x) < 0.5)
		return ((intmax_t)x);
	return (x < 0 ? ft_floor(x) : ft_ceil(x));
}
/*
intmax_t	ft_round(long double x)
{
	return (x < 0 ? x - 0.5 : x + 0.5);
}

double	ft_round(double x)
{
	if (x < 0)
		return (ft_fabs(x) - ft_imaxabs(x) < 0.5 ? (intmax_t)x : ft_floor(x));
	return (ft_fabs(x) - ft_imaxabs(x) < 0.5 ? (intmax_t)x : ft_ceil(x));
}
*/
