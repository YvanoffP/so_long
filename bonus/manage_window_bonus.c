/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:42:38 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/12/17 14:42:56 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	my_mlx_pixel_put(t_img *sprite, int x, int y, int color)
{
	char	*dst;

	dst = sprite->addr + (y * sprite->line_length + x
			* (sprite->bits_pixel / 8));
	*(unsigned int *)dst = color;
}
