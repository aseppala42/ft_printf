#include "libft.h"

long double	ft_sqrtl(long double x)
{
	long double	sqrt;
	long double	n;

	n = x / 2;
	if (!x || x == 1)
		return (x);
	while ((sqrt = (x / n + n) / 2) != n)
		n = sqrt;
	return (sqrt);
}
/*
long double	ft_sqrtl(long double x)
{
	long double	sqrt;
	long double	n;

	sqrt = x / 2;
	n = 0;
	while (sqrt != n)
	{
		n = sqrt;
		sqrt = (x / n + n) / 2;
	}
	return (sqrt);
}
*/
