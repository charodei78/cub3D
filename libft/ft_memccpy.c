/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charodei <hheimerd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:52:55 by charodei          #+#    #+#             */
/*   Updated: 2020/05/01 16:52:56 by charodei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)(src) == (unsigned char)c)
		{
			*(unsigned char *)(dest) = *(unsigned char *)(src);
			return (dest + 1);
		}
		*(unsigned char *)(dest++) = *(unsigned char *)(src++);
	}
	return (0);
}
