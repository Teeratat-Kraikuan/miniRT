/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:44:11 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/22 11:50:22 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "color.h"

# include "camera.h"

typedef struct s_al
{
	double	r;			// ambient lighting ratio in range [0.0,1.0]
	t_color	color;
}	t_al;

typedef struct s_light
{
	t_vect	pos;
	double		b;		// the light brightness ratio in range [0.0,1.0]
	t_color		color;
}	t_light;

typedef enum	e_obj_id
{
	SPHERE,
	PLANE,
	CYLINDER
}				t_obj_id;

typedef struct s_obj
{
	t_obj_id			id;
	void				*content;
	struct s_obj		*next;
}	t_obj;


typedef struct s_sphere
{
	t_vect		center;
	double		d;		// the sphere diameter
	t_color 	color;
}	t_sphere;

typedef struct s_plane
{
	t_vect	pos;
	t_vect	dir;	// 3d normalized normal vector. In range [-1,1] for each x,y,z axis
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vect	pos;
	t_vect	dir;	// 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis
	double		d;		// the cylinder diameter
	double		h;		// the cylinder height
	t_color		color;
}	t_cylinder;

#endif