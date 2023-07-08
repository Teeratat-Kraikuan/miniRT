/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:04:00 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/08 17:31:06 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "minirt_mlx.h"
# include "camera.h"
# include "scene.h"

typedef struct		s_minirt
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_camera		*cam;
	t_scene			*scene;
	t_obj			*objs;
}					t_minirt;

t_minirt	*init_minirt();

#endif