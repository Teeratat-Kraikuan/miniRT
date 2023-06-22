/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:53 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/22 11:56:46 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void draw(t_minirt *minirt)
{
	int			x;
	int			y;

	x = -1;
	while (x++ < WIN_WIDTH - 1)
	{
		y = -1;
		while (y++ < WIN_HEIGHT - 1)
		{
			// setting primary ray
			// ray.orig = camera.pos;
			// ray.dir = normalize(sub_vect(vect(x, y, 0), ray.orig));
			// mlx_pixel_put(minirt->mlx, minirt->win, x, y, get_color(color(128, 0, 0)));
			img_pix_put(&minirt->img, x, y, get_color(color(128, 0, 0)));
		}
	}
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img.img, 0, 0);
}

void	set_camera(t_minirt *minirt)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	cam->pos = vect(0, 0, 0);
	cam->dir = vect(0, 0, 0);
	cam->fov = 0;
	cam->aspect_ratio = (double) WIN_WIDTH / (double) WIN_HEIGHT;
	minirt->cam = cam;
}

void	set_object(t_minirt *minirt)
{
	t_obj		*objs;
	t_sphere	*sphere;

	objs = malloc(sizeof(t_obj));

	sphere = malloc(sizeof(t_sphere));
	sphere->center = vect(0, 0, 20.6);
	sphere->d = 12.6;
	sphere->color = color(10, 0, 255);
	
	objs->id = SPHERE;
	objs->content = (void*) sphere;
	objs->next = NULL;
	minirt->objs = objs;
}

int main( void )
{
	t_minirt *minirt;

	minirt = init_minirt();

	set_camera(minirt);
	set_object(minirt);
	draw(minirt);

	mlx_mouse_hook(minirt->win, &mouse_event, NULL);
	mlx_key_hook(minirt->win, &key_event, NULL);
	mlx_hook(minirt->win, 17, 1L<<5, &close_event, NULL);
    mlx_loop(minirt->mlx);
}
