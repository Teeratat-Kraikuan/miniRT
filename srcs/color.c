/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:53:22 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/13 16:53:03 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color(int r, int g, int b)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int	get_color(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}