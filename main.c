/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:53 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/08 17:54:31 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 2000, 2000, "Tutorial Window - Draw Pixel");

    mlx_pixel_put(mlx, win, 640/2, 360/2, 0xFFFFFF);

    mlx_loop(mlx);
}