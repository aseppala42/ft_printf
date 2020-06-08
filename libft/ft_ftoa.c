#include "libft.h"

char	*ft_ftoa(long double n, int precision)
{
	long double	iprt; //intmax_t
	int		len;
	char		*str;

	n = ft_setprecision(ft_modfl(n, &iprt), precision);
	str = ft_imaxtoa(n * ft_powl(10, precision), 10);
	if ((len = precision - ft_strlen(str)) > 0)
		str = ft_joindel(ft_memset(ft_strnew(len), '0', len), str);
	return (ft_joindel(ft_imaxtoa(iprt, 10), ft_joindel(ft_strdup("."), str)));
}
