/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:15:18 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/06 16:15:32 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	return (*s1 != *s2 || *s1 == '\0' ? *s1 - *s2 : ft_strcmp(s1 + 1, s2 + 1));
}
