/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:53 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/08 19:03:19 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int close_event( void )
{
	exit(0);
}

int mouse_event(int button, int x, int y, void *param)
{
	button = (int) button;
	x = (int) x;
	y = (int) y;
	param = (void *) param;
    printf("%d\n", button);
	return (0);
}

int	key_event(int keycode, void *param)
{
	keycode = (int) keycode;
	param = (void *) param;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int main( void )
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Draw Pixel");

    mlx_pixel_put(mlx, win, 640/2, 360/2, 0xFFFFFF);

	mlx_mouse_hook(win, &mouse_event, NULL);
	mlx_key_hook(win, &key_event, NULL);
	mlx_hook(win, 17, 1L<<5, &close_event, NULL);

    mlx_loop(mlx);
}