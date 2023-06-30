/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:21:20 by tkraikua          #+#    #+#             */
/*   Updated: 2023/07/01 01:23:56 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "minirt_define.h"
# include "vector.h"
# include "ray.h"
# include "stdlib.h"
# include "math.h"
# include "utils.h"

typedef struct s_camera
{
	t_vect			pos;
	t_vect			rot;	// 3d normalized orientation vector. In range [-1,1] for each x,y,z axis
	double			fov;	// FOV : Horizontal field of view in degrees in range [0,180]
	double			aspect_ratio;
	t_ray			*ray;
	t_vect			right;
	t_vect			up;
}	t_camera;

void	calculate_ray(t_camera *camera);

// moving
void	move_forward(t_camera *camera, int speed);
void	move_backward(t_camera *camera, int speed);
void	move_left(t_camera *camera, int speed);
void	move_right(t_camera *camera, int speed);
void	move_up(t_camera *camera, int speed);
void	move_down(t_camera *camera, int speed);

// rotate
void	pitch_cw(t_camera *camera, double speed);
void	pitch_ccw(t_camera *camera, double speed);
void	roll_cw(t_camera *camera, double speed);
void	roll_ccw(t_camera *camera, double speed);

#endif