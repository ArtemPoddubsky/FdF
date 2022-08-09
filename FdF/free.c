/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:10:59 by lholdo            #+#    #+#             */
/*   Updated: 2022/08/09 19:47:15 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mas(char **mas)
{
	int	i;

	if (mas)
	{
		i = 0;
		while (mas[i])
		{
			free(mas[i]);
			i++;
		}
		free(mas);
	}
}

void	free_int_mas(int **mas, int size)
{
	int	i;

	i = 0;
	if (mas[i])
	{
		while (i < size)
		{
			free(mas[i]);
			i++;
		}
		free(mas);
	}
}

void	free_parse_line(char **map_line, t_fdf *fdf, int i)
{
	free_mas(map_line);
	free_int_mas(fdf->altitude, i);
	free_int_mas(fdf->color, i);
	free(fdf);
}

void	free_after_parse(char *line, int fd)
{
	free(line);
	close(fd);
	exit(-1);
}
