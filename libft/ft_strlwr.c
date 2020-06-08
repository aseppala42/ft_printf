#include "libft.h"

char	*ft_strlwr(char *str)
{
	if (!str || *str == 0)
		return (str);
	if (ft_isupper(*str))
		*str += 32;
	ft_strlwr(str + 1);
	return (str);
}
