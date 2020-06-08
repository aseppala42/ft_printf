#include "libft.h"

double	ft_fmod(double x, double y)
{
	while (x > y)
		x -= y;
	return (x);
}
