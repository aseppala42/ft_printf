#include "libft.h"

double	ft_sqrt(double x)
{
	double	sqrt;
	double	n;

	n = x / 2;
	if (!x || x == 1) // lisää equals
		return (x);
	while ((sqrt = (x / n + n) / 2) != n)
		n = sqrt;
	return (sqrt);
}
/*
double	ft_sqrt(double x)
{
	double	sqrt;
	double	n;

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
