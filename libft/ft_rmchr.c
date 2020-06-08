#include "libft.h"

char	*ft_rmchr(char *str, char c)
{
	char	*tmp;

//	str = ft_strdup(str);
	while ((tmp = ft_strchr(str, c)))
		ft_strcpy(tmp, tmp + 1);
	return (str);
}

/*

char	*ft_rmchr(char *src, char c)
{
	char	*dst;

	dst = ft_strnew(ft_strlen(str));
	while (*src != 0)
	{
		if (*dst != c)
			*dst++ = *src;
		src++;
	}
	return (dst);
}

***

char	*ft_rmchr(char *str, char c)
{
	char	tmp;

	if (!str || *str == 0 || !(tmp = ft_strchr(str, c)))
		return (str);
	ft_strcpy(tmp, tmp  + 1);
	ft_rmchr(tmp, c);
	return (str);
}

*/
