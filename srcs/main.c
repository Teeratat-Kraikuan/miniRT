/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:42:53 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/25 02:17:12 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	per_pixel(t_minirt *minirt, double x, double y)
{
	t_ray		ray;
	t_obj		*objs = minirt->objs;
	t_camera	*camera = minirt->cam;

	x = x * 2 - 1;
	y = y * 2 - 1;

	// setting primary ray
	ray.orig = vect(x, y, camera->pos.z);
	ray.dir = vect(x, y, 1);

	// check hit sphere
	t_sphere *sphere = (t_sphere*) objs->content;
	// (bx^2 + by^2)t^2 + (2(axbx + ayby))t + (ax^2 + ay^2 -r^2) = 0
	// this formula use with sphere center is (0, 0, 0)
	// a -> ray origin
	// b -> ray direction
	// r -> radius
	// t -> hit distance

	// quadratic formula form (ax^2 + bx + c = 0) 
	double a = dot_product(ray.dir, ray.dir);
	double b = 2 * dot_product(ray.orig, ray.dir);
	double c = dot_product(ray.orig, ray.orig) - sphere->r * sphere->r;

	// check discriminant
	double discriminant = b * b - 4.0 * a * c;

	if (discriminant < 0)
		return (get_color(color(0, 0, 0)));
	return (get_color(sphere->color));
}

int	ray_trace(t_minirt *minirt, t_ray ray)
{
	t_sphere *sphere = (t_sphere*) minirt->objs->content;

	double a = dot_product(ray.dir, ray.dir);
	double b = 2 * (dot_product(ray.orig, ray.dir) -
				ray.orig.x * sphere->center.x + ray.orig.y * sphere->center.y + ray.orig.z * sphere->center.z);
	double c = pow(ray.orig.x - sphere->center.x, 2) + pow(ray.orig.y - sphere->center.y, 2) + pow(ray.orig.z - sphere->center.z, 2) - pow(sphere->r, 2);

	// check discriminant
	double discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
		return (get_color(color(0, 0, 0)));

	// (-b +- sqrt(discriminant)) / (2.0 * a)
	double t0 = (-b + sqrt(discriminant)) / (2.0 * a);
	double closestT = (-b - sqrt(discriminant)) / (2.0 * a);

	t_vect hit_point = add_vect(ray.orig, multi_vect(ray.dir, closestT));

	t_vect normal = normalize(hit_point);

	t_vect light_dir = normalize(vect(1, 1, 1));

	double d = MAX(dot_product(normal, multi_vect(light_dir, -1)), 0.0); // = cos(angle)
	
	// sphere->color.r = normal.x * 0.5 + 0.5;
	// sphere->color.g = normal.y * 0.5 + 0.5;
	// sphere->color.b = normal.z * 0.5 + 0.5;

	sphere->color.r = 1 * d;
	sphere->color.g = 0 * d;
	sphere->color.b = 1 * d;
	return (get_color(sphere->color));
}

void draw(t_minirt *minirt)
{
	int			x;
	int			y;
	t_ray		ray;

	x = -1;
	while (x++ < WIN_WIDTH - 1)
	{
		y = -1;
		while (y++ < WIN_HEIGHT - 1)
		{
			// setting primary ray
			ray.orig = minirt->cam->pos;
			ray.dir = vect((((double) x / (double) WIN_WIDTH) * 2 - 1) * minirt->cam->aspect_ratio, ((double) y / (double) WIN_HEIGHT) * 2 - 1, 1);
			img_pix_put(&minirt->img, x, y, ray_trace(minirt, ray));
		}
	}
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img.img, 0, 0);
}

void	set_camera(t_minirt *minirt)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	cam->pos = vect(0, 0, -10);
	cam->rot = vect(0, 0, 0);
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
	sphere->center = vect(0, 0, 0);
	sphere->d = 5;
	sphere->r = sphere->d / 2;
	sphere->color = color(136, 8, 8);
	
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
