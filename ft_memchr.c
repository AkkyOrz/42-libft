#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int i;
	const char *str;

	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
