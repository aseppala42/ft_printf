#include "libft.h"

double	ft_pow(double base, int exp)
{
	double	res;
	int	i;

	res = 1;
	i = ft_abs(exp);
	while (i--)
		res *= base;
	return (exp > 0 ? res : 1 / res);
}
/*
double	ft_pow(double base, int exp)
{
	double	res;

	if (!exp)
		return (1);
	res = ft_pow(base, exp / 2);
	if (!(exp % 2))
		return (res * res);
	return (exp > 0 ? res * res * base : (res * res) / base);
}
*/
