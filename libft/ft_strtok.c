#include "libft.h"

char		*ft_strtok(char *restrict str, const char *restrict sep)
{
	static char	*s;

	if (str)
		s = str;
	if (!sep || !s || *s == 0)
		return (0);
	while (ft_strchr(sep, *s))
		s++;
	if (*s == 0)
		return (0);
	str = ft_strndup(s, ft_strcspn(s, sep));
	if ((s = ft_strpbrk(s, sep)))
		while (ft_strchr(sep, *s))
			s++;
	return (str);
}
