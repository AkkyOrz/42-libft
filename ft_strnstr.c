#include "libft.h"
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	index;
	unsigned int	j;

	index = 0;
	if (little[index] == '\0')
		return ((char *)big);
	while (big[index] != '\0' && index < len)
	{
		j = 0;
		while (little[j] != '\0' && index + j < len)
		{
			if (big[index + j] == little[j])
				j++;
			else
				break ;
		}
		if (little[j] == '\0')
			return ((char *)big + index);
		index++;
	}
	return (NULL);
}
