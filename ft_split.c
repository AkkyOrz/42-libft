#include "libft.h"
#include <errno.h>
char **ft_split(char const *s, char c);
static int count_cols(const char *str, char c);
static int set_result(char **res, const char *str, char c);
static int set_result_util(char **res, const char *str, char c);

char **ft_split(char const *str, char c)
{
	char **res;
	int col;

	col = count_cols(str, c);
	if (str == NULL)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (col + 1));
	if (res == NULL)
		return (NULL);
	if (set_result(res, str, c) < 0)
		return (NULL);
	res[col] = NULL;
	return (res);
}

static int count_cols(const char *str, char c)
{
	int i;
	int col;

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

static int set_result(char **res, const char *str, const char c)

{
	int i;
	int size;
	int col;

	i = 0;
	size = 0;
	col = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			size = set_result_util(res + col, str + i, c);
			if (size < 0)
				return (-1);
			i += size;
			col++;
		}
		i++;
	}
	return (1);
}

static int set_result_util(char **res, const char *str, char c)
{
	int len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	*res = ft_substr(str, 0, len);
	if (res == NULL)
		return (-1);
	return (len);
}
