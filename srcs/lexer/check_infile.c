/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 00:00:45 by csantivi          #+#    #+#             */
/*   Updated: 2023/06/29 23:30:36 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*ignore_comment(char *line)
{
	int		i;
	char	*new;

	i = 0;
	while (line[i] && line[i] != '#')
		i++;
	new = ft_substr(line, 0, i);
	return (new);
}

int	check_object(char **data, int *cam)
{
	if (same_str(data[0], "C"))
	{
		*cam += 1;
		return (check_camera(data));
	}
	else if (same_str(data[0], "sp"))
		return (check_sphere(data));
	else
		return (error_unknow_var(data[0]));
}

int	check_line(char *line, int *cam)
{
	char	*new_line;
	char	**data;
	int		error_status;

	if (is_inside('#', line))
	{
		new_line = ignore_comment(line);
		data = ft_split_white(new_line);
		free(new_line);
	}
	else
		data = ft_split_white(line);
	if (data && data[0])
		error_status = check_object(data, cam);
	free_2d(data);
	return (error_status);
}
