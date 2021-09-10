/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:47:34 by akito             #+#    #+#             */
/*   Updated: 2021/09/10 18:23:49 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int64_t	ft_my_putstr(const char *str)
{
	int64_t	res;

	if (str == NULL)
		return (ft_my_putstr("(null)"));
	res = 0;
	while (str[res] != '\0')
		res += ft_my_putchar(str[res]);
	return (res);
}
