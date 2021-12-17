/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:44:09 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/12/17 14:01:32 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_img *sprite, int x, int y, int color)
{
	char	*dst;

	dst = sprite->addr + (y * sprite->line_length + x
			* (sprite->bits_pixel / 8));
	*(unsigned int *)dst = color;
}
