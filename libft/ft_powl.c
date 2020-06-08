#include "libft.h"

long double	ft_powl(long double base, int exp)
{
	long double	res;
	int		i;

	res = 1;
	i = ft_abs(exp);
	while (i--)
		res *= base;
	return (exp > 0 ? res : 1 / res);
}
/*
long double	ft_powl(long double base, int exp)
{
	long double	res;

	if (!exp)
		return (1);
	res = ft_powl(base, exp / 2);
	if (!(exp % 2))
		return (res * res);
	return (exp > 0 ? res * res * base : (res * res) / base);
}
*/
