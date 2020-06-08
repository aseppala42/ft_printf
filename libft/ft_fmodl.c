#include "libft.h"

long double	ft_fmodl(long double x, long double y)
{
	while (x > y)
		x -= y;
	return (x);
}
