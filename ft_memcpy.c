#include "libft.h"
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*to;
	const char	*from;

	to = (char *)dest;
	from = (const char *)src;
	if (from == NULL && to == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dest);
}
