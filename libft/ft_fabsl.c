#include "libft.h"

long double	ft_fabsl(long double n)
{
	return (n < 0 ? -n : n);
}
