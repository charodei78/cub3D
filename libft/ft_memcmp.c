/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charodei <hheimerd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:59:40 by charodei          #+#    #+#             */
/*   Updated: 2020/05/01 17:59:41 by charodei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	while (n--)
	{
		if (*tmp1 != *tmp2)
			return ((*tmp1 - *tmp2));
		tmp1++;
		tmp2++;
	}
	return (0);
}
