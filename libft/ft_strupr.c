#include "libft.h"

char	*ft_strupr(char *str)
{
	if (!str || *str == 0)
		return (str);
	if (ft_islower(*str))
		*str -= 32;
	ft_strupr(str + 1);
	return (str);
}
