/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:25:51 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/07 16:29:12 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int		add_shade(int trgb)
{
	return ((get_t(trgb) / 2) | (get_r(trgb) / 2) | (get_g(trgb) / 2) |
		(get_b(trgb) / 2));
}

int		get_opposite(int trgb)
{
	return ((get_t(trgb)) | ((255 << 16) - get_r(trgb)) | ((255 << 8) -
		get_g(trgb)) | (255 - get_b(trgb)));
}
