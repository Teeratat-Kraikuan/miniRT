/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:53 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/28 18:41:17 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_camera(t_minirt *minirt)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	cam->pos = vect(0, 1, 0);
	cam->rot = vect(0, 0, 0);
	cam->fov = 70;
	cam->aspect_ratio = (double) WIN_WIDTH / (double) WIN_HEIGHT;
	cam->ray = malloc(sizeof(t_ray) * WIN_HEIGHT * WIN_WIDTH);
	calculate_ray(cam);
	minirt->camera = cam;
}

void	set_object(t_minirt *minirt)
{
	t_obj		*objs;
	t_obj		*tmp_obj;
	t_sphere	*sphere;

	objs = malloc(sizeof(t_obj));

	// first sphere
	sphere = malloc(sizeof(t_sphere));
	sphere->center = vect(-2, 0, 10);
	sphere->d = 5;
	sphere->r = sphere->d / 2;
	sphere->color = color(136, 8, 8);
	
	objs->id = SPHERE;
	objs->content = (void*) sphere;
	objs->next = NULL;

	tmp_obj = malloc(sizeof(t_obj));

	// second sphere
	sphere = malloc(sizeof(t_sphere));
	sphere->center = vect(10, 0, 30);
	sphere->d = 5;
	sphere->r = sphere->d / 2;
	sphere->color = color(20, 8, 138);

	tmp_obj->id = SPHERE;
	tmp_obj->content = (void*) sphere;
	tmp_obj->next = NULL;

	objs->next = tmp_obj;
	
	minirt->objs = objs;
}

int main( void )
{
	t_minirt *minirt;

	minirt = init_minirt();

	set_camera(minirt);
	set_object(minirt);

	// mlx_mouse_hook(minirt->win, &mouse_event, NULL);
	// mlx_key_hook(minirt->win, &key_event, minirt);
	mlx_loop_hook(minirt->mlx, &loop_event, minirt);
	mlx_hook(minirt->win, KeyPress, KeyPressMask, &handle_keypress, minirt);
	mlx_hook(minirt->win, KeyRelease, KeyReleaseMask, &handle_keyrelease, minirt);
	mlx_hook(minirt->win, DestroyNotify, NoEventMask, &close_event, minirt);
    mlx_loop(minirt->mlx);
}
