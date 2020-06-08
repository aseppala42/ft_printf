#include "libft.h"

static size_t	ft_imaxlen(intmax_t n, int base)
{
	if ((n < 0 && base != 10) || base < MIN_BASE || base > MAX_BASE)
		return (0);
	if (n < 0)
		return (1 + ft_imaxlen(-n, base));
	if (n > base - 1)
		return (1 + ft_imaxlen(n / base, base));
	return (1);
}

/*

char		*ft_recursive_imaxtoa(char *str, intmax_t n, int base, int i)
{
	if (n < 0)
	{
		str[0] = '-';
		return (ft_recursive_imaxtoa(str, -n, base, i));
	}
	str[i] = (n % base > 9) ? n % base - 10 + 'a' : n % base + '0';
	if (n > base - 1)
		ft_recursive_imaxtoa(str, n / base, base, --i);
	return (str);
}

char		*ft_imaxtoa(intmax_t n, int base)
{
	char	*str;
	size_t	len;

	if ((n < 0 && base != 10) || base < MIN_BASE || base > MAX_BASE)
		return (0);
	len = ft_imaxlen(n, base);
	if (!(str = ft_strnew(len)))
		return (0);
	return (ft_recursive_imaxtoa(str, n, base, --len));
}

**

char		*ft_recursive_imaxtoa(char *str, intmax_t n, int base, int i)
{
	if (n < 0)
	{
		ft_recursive_imaxtoa(str, -n, base);
		*(str + ft_strlen(str)) = '-';
		return (str);
	}
	*str = (n % base > 9) ? n % base - 10 + 'a' : n % base + '0';
	if (n > base - 1)
		ft_recursive_imaxtoa(str, n / base, base);
	return (str);
}

char		*ft_imaxtoa(intmax_t n, int base)
{
	char	*str;

	if ((n < 0 && base != 10) || base < MIN_BASE || base > MAX_BASE)
		return (0);
	if (!(str = ft_strnew(ft_imaxlen(n, base))))
		return (0);
	return (ft_strrev(ft_recursive_imaxtoa(str, n, base)));
}

*/

char		*ft_imaxtoa(intmax_t n, int base)
{
	char	*str;
	char	*tmp;
	int	sign;

	if ((n < 0 && base != 10) || base < MIN_BASE || base > MAX_BASE)
		return (0);
	if (!(str = ft_strnew(ft_imaxlen(n ,base))))
		return (0);
	tmp = str;
	if ((sign = (n < 0)))
		n = -n;
	*tmp++ = (n % base > 9) ? n % base - 10 + 'a' : n % base + '0'; // char *digits = DIGITS, digits[n % base] // DIGITS[n % base]
	while ((n /= base))
		*tmp++ = (n % base > 9) ? n % base - 10 + 'a' : n % base + '0';
	if (sign)
		*tmp = '-';
	return (ft_strrev(str));
}

/*

char		*ft_imaxtoa(intmax_t n, int base)
{
	if ((n < 0 && base != 10) || base < MIN_BASE || base > MAX_BASE)
		return (0);
	if (n < 0)
		return (ft_joindel("-", ft_imaxtoa(-n)));
	if (n > base - 1)
		return (ft_joindel(ft_imaxtoa(n / base),
		ft_chrjoin((n % base > 9) ? n % base - 10 + 'a' : n % base + '0', 0)));
	return (ft_chrjoin((n % base > 9) ? n % base - 10 + 'a' : n % base + '0', 0));
}

*/
