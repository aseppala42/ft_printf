#include "libft.h"
/*
double	ft_modf(double value, double *iptr)
{
	*iptr = (intmax_t)value;
	return (ft_fmod(value, 1));
}
*/
double	ft_modf(double value, double *iptr)
{
	*iptr = (intmax_t)value;
	return (ft_fabs(value) - ft_imaxabs(*iptr));
}
