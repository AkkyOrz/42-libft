#include "libft.h"
static int ft_startwith(char const *str, char const *prefix);
static char *ft_string_merge(const char *s1, const char *s2, int i);
char *ft_strjoin(char const *s1, char const *s2)
{
	unsigned int i;
	unsigned int s1_len;
	char *res;

	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	i = -1;
	while (++i < s1_len)
	{
		if (ft_startwith(s2, s1 + i) > 0)
		{
			res = ft_string_merge(s1, s2, i);
			if (res == NULL)
				return (NULL);
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

static char *ft_string_merge(const char *s1, const char *s2, int i)
{
	char *res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) - i + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	*res = '\0';
	ft_strlcat(res, s1 + i, ft_strlen(s1) - i + 1);
	ft_strlcat(res, s2, ft_strlen(s2) + 1);
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
