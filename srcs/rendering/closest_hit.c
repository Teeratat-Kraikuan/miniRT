/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 11:29:02 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/28 13:54:39 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

t_payload	miss(t_ray ray)
{
	t_payload	payload;

	payload.hit_distance = -1;
	return (payload);
}

void	closest_hit_sp(t_ray ray, double hit_d, t_sphere *s, t_payload *l)
{
	t_vect	origin;

	origin = sub_vect(ray.orig, s->center);
	l->world_pos = add_vect(origin, multi_vect(ray.dir, hit_d));
	l->world_norm = normalize(l->world_pos);
	l->world_pos = add_vect(l->world_pos, s->center);
}

void	closest_hit_pl(t_ray ray, double hit_d, t_plane *p, t_payload *l)
{
	l->world_norm = p->dir;
	l->world_pos = add_vect(ray.orig, multi_vect(ray.dir, hit_d));
}

void	closest_hit_cy(t_ray ray, double hit_d, t_cylinder *cy, t_payload *load)
{
	t_vect	origin = sub_vect(ray.orig, cy->center);
	// t_vect	origin = ray.orig;
	load->world_pos = add_vect(origin, multi_vect(ray.dir, hit_d));
	// load->world_norm = multi_vect(ray.dir, -1);
	double t = dot_product(load->world_pos, cy->dir);
	load->world_pos = add_vect(load->world_pos, cy->center);

	t_vect pt = add_vect(cy->center, multi_vect(cy->dir, t));
	load->world_norm = normalize(sub_vect(load->world_pos, pt));

	// float m = dot_product(ray.dir, multi_vect(cy->dir, hit_d)) + dot_product(origin, cy->dir);
	// load->world_norm = normalize()

	if (t >= cy->h / 2 - EPSILON || t <= -cy->h / 2 + EPSILON)
	{
		if (t >= cy->h / 2 - EPSILON)
			load->world_norm = cy->dir;
		else if (t <= -cy->h / 2 + EPSILON)
			load->world_norm = multi_vect(cy->dir, -1);
	}

	// load->world_norm = normalize(vect(load->world_pos.x - cy->center.x, load->world_pos.y, load->world_pos.z - cy->center.z));
}

t_payload	get_closest_hit(t_ray ray, double hit_d, t_obj *obj)
{
	t_payload	load;

	load.obj = obj;
	load.hit_distance = hit_d;
	if (obj->id == SPHERE)
		closest_hit_sp(ray, hit_d, (t_sphere *) obj->content, &load);
	else if (obj->id == PLANE)
		closest_hit_pl(ray, hit_d, (t_plane *) obj->content, &load);
	else if (obj->id == CYLINDER)
		closest_hit_cy(ray, hit_d, (t_cylinder *) obj->content, &load);
	return (load);
}
