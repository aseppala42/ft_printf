#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	if (*s == 0 || *charset == 0)
		return (0);
	if (ft_strchr(charset, *s))
		return ((char *)s);
	return (ft_strpbrk(++s, charset));
}
