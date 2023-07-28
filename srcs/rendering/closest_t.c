/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:42:38 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/27 01:22:28 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

int	hit_plane(t_plane *p, t_ray ray, double *closestT)
{
	double	denom;

	denom = dot_product(p->dir, ray.dir);
	if (fabs(denom) > 0.0001)
	{
		*closestT = dot_product(sub_vect(p->center, ray.orig), p->dir) / denom;
		if (*closestT > 0.0001)
		{
			t_vect point = add_vect(ray.orig, multi_vect(ray.dir, *closestT));
			t_vect v;
			v = sub_vect(point, p->center);
			double d2 = dot_product(v, v);
			if (sqrtf(d2) <= 5)
				return (1);
			// return (1);
		}
	}
	return (0);
}

int	hit_sphere(t_sphere *sphere, t_ray ray, double *closestT)
{
	t_vect	origin;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	origin = sub_vect(ray.orig, sphere->center);
	a = dot_product(ray.dir, ray.dir);
	b = 2 * dot_product(origin, ray.dir);
	c = dot_product(origin, origin) - sphere->r * sphere->r;
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
		return (0);
	*closestT = (-b - sqrt(discriminant)) / (2.0 * a);
	if (*closestT < 0)
			*closestT = (-b + sqrt(discriminant)) / (2.0 * a);
	return (1);
}

int	hit_cylinder(t_cylinder *cy, t_ray ray, double *closestT)
{
	t_vect	originxdir = cross_product(sub_vect(ray.orig, cy->center), cy->dir);
    t_vect  rdxdir = cross_product(ray.dir, cy->dir);
    float   a = dot_product(rdxdir, rdxdir);
    float   b = 2 * dot_product(rdxdir, originxdir);
    float   c = dot_product(originxdir, originxdir) - (cy->r * cy->r);
	
	// check discriminant
	double discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0)
		return (0);
	*closestT = (-b - sqrt(discriminant)) / (2.0 * a);
	if (*closestT < 0)
			*closestT = (-b + sqrt(discriminant)) / (2.0 * a);

	// complicated algorithm
	t_vect	origin = sub_vect(ray.orig, cy->center);
	t_vect world_pos = add_vect(origin, multi_vect(ray.dir, *closestT));
	double t = dot_product((sub_vect(world_pos, cy->center)), normalize(cy->dir));
	if (t >= cy->h / 2 || t <= -cy->h / 2)
	{
		*closestT = DBL_MAX;
		double	denom;
		denom = dot_product(cy->dir, ray.dir);
		if (fabs(denom) > 0.0001)
		{
			if (t >= cy->h / 2)
				*closestT = dot_product(sub_vect(cy->top, ray.orig), cy->dir) / denom;
			else if (t <= -cy->h / 2)
				*closestT = dot_product(sub_vect(cy->bottom, ray.orig),cy->dir) / denom;
			if (*closestT > 0.0001)
			{
				t_vect p = add_vect(ray.orig, multi_vect(ray.dir, *closestT));
				t_vect v;
				if (t >= cy->h / 2)
					v = sub_vect(p, cy->top);
				else
					v = sub_vect(p, cy->bottom);
				double d2 = dot_product(v, v);
				if (sqrtf(d2) <= cy->r)
					return (1);
			}
		}
		return (0);
	}

	// cylinder caps
	
	return (1);
}

double	get_closestt(t_obj *obj, t_ray ray, double *closestT)
{
	if (obj->id == SPHERE)
		return (hit_sphere((t_sphere *) obj->content, ray, closestT));
	if (obj->id == PLANE)
		return (hit_plane((t_plane *) obj->content, ray, closestT));
	if (obj->id == CYLINDER)
		return (hit_cylinder((t_cylinder *) obj->content, ray, closestT));
	return (0);
}
