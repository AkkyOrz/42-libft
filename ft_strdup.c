#include "libft.h"
#include <errno.h>
#include <stdint.h>
char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	if (len > SIZE_MAX - 1)
	{
		errno = ENOMEM;
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}
