/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charodei <hheimerd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:30:51 by charodei          #+#    #+#             */
/*   Updated: 2020/05/05 20:30:53 by charodei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cellcount(const char *str, char c)
{
	size_t		count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static char		**del_arr(char ***arr)
{
	char	**tmp;

	if (!arr)
		return (NULL);
	if (*arr)
	{
		tmp = *arr;
		while (*tmp)
			free(*(tmp++));
		free(*arr);
	}
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;
	size_t	len;

	len = cellcount(s, c);
	if (!(res = (char **)ft_calloc((len + 1), sizeof(char *))))
		return (NULL);
	if (!len)
		return (res);
	count = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		if (!*s)
			return (res);
		while (*s != c && *s)
			s += 1 + (len++) * 0;
		if (!(res[count++] = ft_substr(s - len, 0, len)))
			return (del_arr(&res));
	}
	return (res);
}
