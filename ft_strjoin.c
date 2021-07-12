#include "libft.h"
static int ft_startwith(char const *str, char const *prefix);
char *ft_strjoin(char const *s1, char const *s2)
{
	unsigned int i;
	const unsigned int s1_len = ft_strlen(s1);
	char *res;

	i = -1;
	while (++i < s1_len)
	{
		if (ft_startwith(s2, s1 + i) > 0)
		{
			res = (char *)malloc(sizeof(char) * (s1_len - i + ft_strlen(s2) + 1));
			if (res == NULL)
				return (NULL);
			*res = '\0';
			ft_strlcat(res, s1 + i, s1_len - i + 1);
			ft_strlcat(res, s2, ft_strlen(s2) + 1);
			return (res);
		}
	}
	res = (char *)malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	*res = '\0';
	ft_strlcat(res, s1, s1_len + 1);
	ft_strlcat(res, s2, s1_len + ft_strlen(s2) + 1);
	return (res);
}

// return overlap string length
static int ft_startwith(char const *str, char const *prefix)
{
	int i;

	i = 0;
	while (prefix[i] != '\0')
	{
		if (str[i] != prefix[i])
		{
			return (-1);
		}
		i++;
	}
	return (ft_strlen(prefix));
}
