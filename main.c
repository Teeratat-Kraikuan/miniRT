/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:53 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/13 17:28:52 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
    void *win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Tutorial Window - Draw Pixel");

	int			x;
	int			y;

	x = -1;
	while (x++ < WIN_WIDTH - 1)
	{
		y = -1;
		while (y++ < WIN_HEIGHT - 1)
		{
			mlx_pixel_put(mlx, win, x, y, get_color(color(128, 0, 0)));
			// img_pix_put(&fractal->img, x, y, get_color(f));
		}
	}
	// mlx_put_image_to_window(mlx, win, fractal->img.img, 0, 0);

	mlx_mouse_hook(win, &mouse_event, NULL);
	mlx_key_hook(win, &key_event, NULL);
	mlx_hook(win, 17, 1L<<5, &close_event, NULL);

    mlx_loop(mlx);
}
