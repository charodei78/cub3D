/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charodei <hheimerd@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:09:44 by charodei          #+#    #+#             */
/*   Updated: 2020/04/30 15:09:47 by charodei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_isalnum(int c)
{
	c = (char)c;
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (8);
	return (0);
}
