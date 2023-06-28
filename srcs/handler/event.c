/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:24:09 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/28 21:55:22 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

int i = 0;

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

// int	key_event(int keycode, void *param)
// {
// 	t_minirt *minirt;
	
// 	minirt = (t_minirt *) param;
// 	// printf("keycode -> %d\n", keycode);
// 	if (keycode == KEY_ESC)
// 		exit(0);
// 	else if (keycode == LEFT_SQUARE_BRACKETS)
// 		minirt->cam->fov -= 2;
// 	else if (keycode == RIGHT_SQUARE_BRACKETS)
// 		minirt->cam->fov += 2;
// 	calculate_ray(minirt->cam);
// 	draw(minirt);
// 	return (0);
// }

int handle_keypress(int keycode, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt*) param;
	// printf("keypresed -> %d\n", keycode);
	if (keycode == LEFT_SQUARE_BRACKETS)
		minirt->camera->fov -= 1;
	else if (keycode == RIGHT_SQUARE_BRACKETS)
		minirt->camera->fov += 1;
	else if (keycode == KEY_A)
		minirt->camera->pos.x -= 0.1;
	else if (keycode == KEY_S)
		minirt->camera->pos.z -= 0.1;
	else if (keycode == KEY_D)
		minirt->camera->pos.x += 0.1;
	else if (keycode == KEY_W)
		minirt->camera->pos.z += 0.1;
	return (0);
}

int handle_keyrelease(int keycode, void *param)
{
	// printf("keyreleased -> %d\n", keycode);
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int loop_event(void *param)
{
	t_minirt *minirt;

	minirt = (t_minirt*) param;
	calculate_ray(minirt->camera);
	draw(minirt);
	// printf("%d\n", i++);
	// printf("fov = %lf\n", minirt->camera->fov);
	// printf("camera position = (%lf, %lf, %lf)\n", minirt->camera->pos.x, minirt->camera->pos.y, minirt->camera->pos.z);
	return (0);
}