/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheimerd <hheimerd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:17:04 by hheimerd          #+#    #+#             */
/*   Updated: 2020/09/23 16:30:27 by hheimerd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		rgba(int r, int g, int b, float t)
{
	int tmp;

	t *= 255;
	tmp = t;
	tmp %= 256;
	tmp = 255 - tmp;
	return (tmp << 24 | (r % 256) << 16 | (g % 256) << 8 | (b % 256));
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & (0xFF));
}
