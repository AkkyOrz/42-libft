#include "libft.h"
int	ft_startwith(char const *str, char const *prefix)
{
	int	i;

	i = 0;
	while (prefix[i] != '\0')
	{
		if (str[i] != prefix[i])
			return (-1);
		i++;
	}
	return (ft_strlen(prefix));
}
