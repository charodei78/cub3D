/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charodei <hheimerd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:15:46 by charodei          #+#    #+#             */
/*   Updated: 2020/05/06 19:15:48 by charodei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	count;

	res = 0;
	if (s && f)
	{
		if (!(res = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char))))
			return (NULL);
		count = 0;
		while (s[count])
		{
			res[count] = f(count, s[count]);
			count++;
		}
		res[count] = '\0';
	}
	return (res);
}
