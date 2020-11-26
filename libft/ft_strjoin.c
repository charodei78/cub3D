/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charodei <hheimerd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 22:50:25 by charodei          #+#    #+#             */
/*   Updated: 2020/05/02 22:50:26 by charodei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	count;

	if (!s1 || !s2)
		return (NULL);
	count = 0;
	if (!(result =
		(char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * (sizeof(char)))))
		return (NULL);
	while (*s1)
	{
		*(result++) = *(s1++);
		count++;
	}
	while (*s2)
	{
		*(result++) = *(s2++);
		count++;
	}
	*result = '\0';
	return (result - count);
}
