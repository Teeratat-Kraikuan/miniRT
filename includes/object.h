/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:44:11 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/09 17:08:12 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "color.h"

typedef struct s_al
{
	double	r;			// ambient lighting ratio in range [0.0,1.0]
	t_color	color;
}	t_al;

typedef struct s_camera
{
	t_vector	pos;
	t_vector	dir;	// 3d normalized orientation vector. In range [-1,1] for each x,y,z axis
	int			fov;	// FOV : Horizontal field of view in degrees in range [0,180]
}	t_camera;

typedef struct s_light
{
	t_vector	pos;
	double		b;		// the light brightness ratio in range [0.0,1.0]
	t_color		color;
}	t_light;

typedef struct s_sphere
{
	t_vector	pos;
	double		d;		// the sphere diameter
	t_color 	color;
}	t_sphere;

typedef struct s_plane
{
	t_vector	pos;
	t_vector	dir;	// 3d normalized normal vector. In range [-1,1] for each x,y,z axis
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	pos;
	t_vector	dir;	// 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis
	double		d;		// the cylinder diameter
	double		h;		// the cylinder height
	t_color		color;
}	t_cylinder;

#endif