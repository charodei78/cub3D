/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charodei <hheimerd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 16:29:20 by charodei          #+#    #+#             */
/*   Updated: 2020/05/14 16:29:22 by charodei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list			*ft_create_elem(int fd, char *left, t_list *prev)
{
	t_list				*res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	res->fd = fd;
	res->left = left;
	res->prev = prev;
	res->next = NULL;
	return (res);
}

char			*ft_strjoin(char *s1, char *s2)
{
	char		*result;
	size_t		i;
	size_t		j;

	if (!s1 && s2)
		return (ft_strdup((const char*)s2));
	if (s1 && !s2)
		return (s1);
	i = -1;
	if (!(result = (char *)malloc((ft_strlen(s1) +
		ft_strlen(s2) + 1) * (sizeof(char)))))
	{
		free(s1);
		return (NULL);
	}
	while (s1[++i])
		result[i] = s1[i];
	free(s1);
	j = -1;
	while (s2[++j])
		result[i + j] = s2[j];
	result[i + j] = '\0';
	return (result);
}

char			*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

char			*ft_strdup(const char *s)
{
	char		*res;
	size_t		len;

	len = ft_strlen(s);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s)
	{
		while (*s)
			*(res++) = *(s++);
	}
	*res = '\0';
	return (res - len);
}

size_t			ft_strlen(const char *s)
{
	size_t		count;

	if (!s)
		return (0);
	count = 0;
	while (*(s++))
		count++;
	return (count);
}
