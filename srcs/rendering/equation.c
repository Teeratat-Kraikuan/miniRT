/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:26:26 by csantivi          #+#    #+#             */
/*   Updated: 2023/07/27 00:59:29 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

t_vect	reflect(t_vect incident, t_vect norm)
{
	t_vect	multi;

	multi = multi_vect(norm, 2.0 * dot_product(incident, norm));
	return (sub_vect(incident, multi));
}

t_vect	new_ray_origin(t_payload *load)
{
	t_vect	new_norm;

	new_norm = multi_vect(load->world_norm, 0.001);
	return (add_vect(load->world_pos, new_norm));
}
