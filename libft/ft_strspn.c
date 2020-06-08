#include "libft.h"

size_t	ft_strspn(const char *s, const char *charset)
{
	if (*s == 0 || !ft_strchr(charset, *s))
		return (0);
	return (1 + ft_strspn(++s, charset));
}
