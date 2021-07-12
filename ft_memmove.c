#include "libft.h"
void *ft_memmove(void *dest, const void *src, size_t n)
{
	int i;
	char *to;
	const char *from;

	to = (char *)dest;
	from = (const char *)src;
	if (from == NULL && to == NULL)
		return (NULL);
	if (from > to)
		ft_memcpy(dest, src, n);
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			to[i] = from[i];
			i--;
		}
	}
	return (dest);
}
