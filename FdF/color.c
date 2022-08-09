/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:09:39 by lholdo            #+#    #+#             */
/*   Updated: 2022/08/09 11:46:10 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double	place;
	double	dist;

	place = current - start;
	dist = end - start;
	if (dist == 0)
		return (1.0);
	else
		return (place / dist);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_default_color(int z, t_fdf *fdf)
{
	double	percentage;

	percentage = percent(fdf->z_min, fdf->z_max, z);
	if (percentage < 0.2)
		return (PURPLE);
	else if (percentage < 0.4)
		return (PINK);
	else if (percentage < 0.6)
		return (RED);
	else if (percentage < 0.8)
		return (ORANGE);
	else
		return (YELLOW);
}

int	get_color(t_fdf *fdf, t_draw *coor)
{
	if (fdf->color[coor->y][coor->x] == -1)
		return (get_default_color(fdf->altitude[coor->y][coor->x], fdf));
	else
		return (fdf->color[coor->y1][coor->x1]);
}
