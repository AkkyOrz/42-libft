#include "libft.h"
#include <stdlib.h>
#include <errno.h>

char		**ft_split(char const *s, char c);
static int	count_cols(const char *str, char c);
static char	*ft_strcdup(const char *str, char c);
static char	**set_words(char **res, const char *str,
				const int col, const char c);
static char	**clear_all(char **res, int col_i);

char	**ft_split(char const *str, char c)
{
	char	**res;
	int		col;

	if (str == NULL)
		return (NULL);
	col = count_cols(str, c);
	res = (char **)malloc(sizeof(char *) * (col + 1));
	if (res == NULL)
		return (NULL);
	res = set_words(res, str, col, c);
	if (res == NULL)
		return (NULL);
	res[col] = NULL;
	return (res);
}

static int	count_cols(const char *str, char c)
{
	int	i;
	int	col;

	i = 0;
	col = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			col++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (col);
}

static char	*ft_strcdup(const char *str, char c)
{
	int		len;
	char	*res;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	res = ft_substr(str, 0, len);
	if (res == NULL)
		return (res);
	return (res);
}

static char	**set_words(char **res, const char *str,
			const int col, const char c)
{
	int	str_i;
	int	col_i;

	str_i = 0;
	col_i = 0;
	while (col_i < col)
	{
		if (str[str_i] == c)
		{
			str_i++;
			continue ;
		}
		res[col_i] = ft_strcdup(str + str_i, c);
		if (res[col_i] == NULL)
			return (clear_all(res, col_i));
		str_i += ft_strlen(res[col_i]);
		col_i++;
	}
	return (res);
}

static char	**clear_all(char **res, int col_i)
{
	while (col_i >= 0)
	{
		free(res[col_i]);
		res[col_i] = NULL;
		col_i--;
	}
	free(res);
	res = NULL;
	return (res);
}
