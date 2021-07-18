#include "libft.h"
static int	ft_min(int a, int b);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	len = ft_min(len, ft_strlen(s) - start);
	res = (char *)malloc(sizeof(char) * (len) + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s + start, len + 1);
	return (res);
}

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
