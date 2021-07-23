#include "libft.h"
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*to;
	const char	*from;

	to = (char *)dest;
	from = (const char *)src;
	if (from == NULL && to == NULL)
		return (NULL);
	if (from > to)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			to[i - 1] = from[i - 1];
			i--;
		}
	}
	return (dest);
}
