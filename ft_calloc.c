#include "libft.h"
#include <limits.h>
#include <errno.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb > (LONG_MAX / size))
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
