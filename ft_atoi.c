#include "libft.h"
#include <limits.h>
int			ft_atoi(const char *nptr);
static void	read_sign(int *sign, size_t *i, char c);
static int	ft_isspace(int c);
static int	overflow_num(long long result, int sign, int overflow);

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	long long	result;
	int			overflow;

	i = 0;
	result = 0;
	sign = 1;
	overflow = 0;
	while (ft_isspace(nptr[i]))
		i++;
	read_sign(&sign, &i, nptr[i]);
	while (ft_isdigit(nptr[i]))
	{
		if (result > (LONG_MAX / 10))
			overflow = 1;
		result *= 10;
		if (result > (LONG_MAX - (nptr[i] - '0')))
			overflow = 1;
		if (overflow)
			break ;
		result += (nptr[i] - '0');
		i++;
	}
	return (overflow_num(result, sign, overflow));
}

static void	read_sign(int *sign, size_t *i, char c)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*sign *= -1;
		(*i)++;
	}
}

static int	ft_isspace(int c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

static int	overflow_num(long long result, int sign, int overflow)
{
	if (overflow)
	{
		if (sign == 1)
			return (-1);
		if (sign == -1)
			return (0);
	}
	return (result * sign);
}
