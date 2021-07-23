#include "libft.h"
#include <limits.h>
#include <errno.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (size == 0 || nmemb == 0)
		return (NULL);
	if (nmemb > (SIZE_MAX / size))
	{
		errno = ENOMEM;
		return (NULL);
	}
	res = (void *)malloc(nmemb * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, size * nmemb);
	return (res);
}
