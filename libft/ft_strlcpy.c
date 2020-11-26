/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charodei <hheimerd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:09:09 by charodei          #+#    #+#             */
/*   Updated: 2020/04/30 17:09:10 by charodei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	count;

	if (!dst && !src)
		return (0);
	count = ft_strlen(src);
	if (!size)
		return (count);
	while (--size && *src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (count);
}
