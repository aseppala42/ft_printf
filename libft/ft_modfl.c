#include "libft.h"
/*
long double	ft_modfl(long double value, long double *iptr)
{
	*iptr = (intmax_t)value;
	return (ft_fmodl(value, 1));
}
*/
long double	ft_modfl(long double value, long double *iptr)
{
	*iptr = (intmax_t)value;
	return (ft_fabsl(value) - ft_imaxabs(*iptr));
}
