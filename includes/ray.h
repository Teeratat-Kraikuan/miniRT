/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:46:18 by tkraikua          #+#    #+#             */
/*   Updated: 2023/06/24 21:53:34 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "minirt.h"

typedef struct	s_ray
{
	t_vect	orig;	// ray origin
	t_vect	dir;	// ray direction
}	t_ray;

// return color
int	rayTrace(t_ray ray);

#endif