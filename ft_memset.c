#include "libft.h"
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;
	char			*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
