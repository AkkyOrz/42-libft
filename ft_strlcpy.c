#include "libft.h"

static void	*string_copy(char *dest, const char *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < size)
	{
		string_copy(dst, src, src_len + 1);
	}
	else if (size != 0)
	{
		string_copy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_len);
}

static void	*string_copy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
