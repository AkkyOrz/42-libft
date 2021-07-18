#include "libft.h"
#include <limits.h>
int			ft_atoi(const char *nptr);
static int	ft_isspace(int c);

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	result *= sign;
	return ((int)result);
}

static int	ft_isspace(int c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}
