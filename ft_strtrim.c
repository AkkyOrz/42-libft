#include "libft.h"
static int	is_charset_include(const char c, const char *charset);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		prefix_len;
	int		suffix_len;
	char	*res;
	int		res_len;
	int		s1_len;

	if (s1 == NULL)
		return (NULL);
	prefix_len = 0;
	s1_len = ft_strlen(s1);
	while (is_charset_include(s1[prefix_len], set) != 0)
		prefix_len++;
	if (prefix_len == s1_len)
		return (ft_strdup(""));
	suffix_len = 0;
	while (is_charset_include(s1[s1_len - 1 - suffix_len], set) != 0)
		suffix_len++;
	res_len = s1_len - (prefix_len + suffix_len) + 1;
	res = (char *)malloc(sizeof(char) * res_len);
	ft_strlcpy(res, s1 + prefix_len, res_len);
	return (res);
}

static int	is_charset_include(const char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}
