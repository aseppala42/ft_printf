#include "libft.h"

char	*ft_strrev(char *str)
{
	if (str && *str != 0)
		return (ft_strnrev(str, 0, ft_strlen(str) - 1));
	return (str);
}
