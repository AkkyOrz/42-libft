#include "libft.h"
char *ft_substr(char const *s, unsigned int start,
size_t len)
{
	char *res;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) - start <= len)
		len = ft_strlen(s) - start;
	res = (char *)malloc(sizeof(char) * (len) + 1);
	if (res == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}
