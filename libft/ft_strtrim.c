/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charodei <hheimerd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 12:19:13 by charodei          #+#    #+#             */
/*   Updated: 2020/05/05 12:19:16 by charodei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strlcut(char *start, char *end)
{
	char	*res;
	size_t	len;

	len = end - start;
	if (!(res = (char *)malloc((len + 2) * sizeof(char))))
		return (NULL);
	while (start <= end)
		*(res++) = *(start++);
	*res = '\0';
	return (res - len - 1);
}

static char		*forbiddden(char *s, char *c, int step)
{
	char	sw;
	char	*ctmp;

	ctmp = c;
	while (*s)
	{
		sw = 0;
		while (*c)
		{
			if (*s == *c)
			{
				sw = 1;
				break ;
			}
			c++;
		}
		if (!sw)
			return (s);
		c = ctmp;
		s += step;
	}
	return ("");
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	if (!*set)
		return (ft_strdup(s1));
	if (!(*s1))
		return ("");
	start = forbiddden((char *)s1, (char *)set, 1);
	while (*s1)
		s1++;
	end = forbiddden((char *)s1 - 1, (char *)set, -1);
	return (ft_strlcut(start, end));
}
