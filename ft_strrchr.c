#include "libft.h"
char	*ft_strrchr(const char *s, int c)
{
	unsigned int i;
	char *last_c;

	i = 0;
	last_c = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			last_c = (char *)s + i;
		i++;
	}
	if (s[i] == c)
		last_c = (char *)s + i;
	return (last_c);
}
