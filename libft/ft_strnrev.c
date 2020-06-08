#include "libft.h"

char	*ft_strnrev(char *str, size_t start, size_t end)
{
	char	tmp;

	if (!str || *str == 0)
		return (0);
	if (start >= end)
		return (str);
	tmp = *(str + start);
	*(str + start) = *(str + end);
	*(str + end) = tmp;
	ft_strnrev(str, ++start, --end);
	return (str);
}

/*

char	*ft_strnrev(char *str, size_t len)
{
	char	tmp;

	if (!str || *str == 0)
		return (0);
	if (!len || len == 1)
		return (str);
	tmp = *str;
	*str = *(str + --len);
	*(str + len) = tmp;
	ft_strnrev(++str, --len);
	return (str);
}

*/
