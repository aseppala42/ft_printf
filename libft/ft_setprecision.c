#include "libft.h"
/*
long double	ft_setprecision(long double x, int precision)
{
	long double	iprt;

	x = ft_modfl(x, &iprt);
	x = ft_roundl(ft_powl(10, precision) * x) / ft_powl(10, precision);
	return (iprt + x);
}
*/
long double	ft_setprecision(long double x, int precision)
{
	return (ft_roundl(ft_powl(10, precision) * x) / ft_powl(10, precision));
}
