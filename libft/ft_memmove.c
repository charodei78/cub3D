/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charodei <hheimerd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:08:00 by charodei          #+#    #+#             */
/*   Updated: 2020/05/01 17:08:02 by charodei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void			*tmp;
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	tmp = dest;
	if (dest < src)
	{
		while (n--)
			*(d++) = *(s++);
		return (tmp);
	}
	else if (dest > src)
	{
		while (n--)
			d[n] = s[n];
		return (dest);
	}
	else
		return (dest);
}
