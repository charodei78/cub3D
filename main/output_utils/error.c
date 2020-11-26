/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 10:55:33 by hheimerd          #+#    #+#             */
/*   Updated: 2020/08/28 10:59:25 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int		ft_put_error(char *message, int code)
{
	ft_putstr_fd(message, 2);
	return (code);
}
