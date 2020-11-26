/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:27:27 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/06 17:40:34 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_arrinit(int height, int length)
{
	char	**res;

	if (!(res = (char**)malloc(height * sizeof(char*))))
		return (NULL);
	while (height--)
		if (!(res[height] = (char*)malloc(length * sizeof(char))))
			return (NULL);
	return (res);
}
