#include "libft.h"
#include <stdio.h>
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int i;
	unsigned const char *str;

	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
