#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;

	if (s1 == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	*res = '\0';
	ft_strlcat(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (res);
}

// return overlap string length

