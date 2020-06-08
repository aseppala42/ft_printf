#include "libft.h"

size_t	ft_strcspn(const char *s, const char *charset)
{
	if (*charset == 0)
		return (ft_strlen(s));
	if (*s == 0 || ft_strchr(charset, *s))
		return (0);
	return (1 + ft_strcspn(++s, charset));
}
