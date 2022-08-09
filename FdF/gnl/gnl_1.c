/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:11:36 by lholdo            #+#    #+#             */
/*   Updated: 2021/10/25 16:11:37 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_1.h"

static t_fil	*new_file_1(const int fd)
{
	t_fil	*new;

	new = (t_fil *)malloc(sizeof(t_fil));
	if (new)
	{
		new->fd = fd;
		new->str = NULL;
	}
	return (new);
}

static t_fil	*get_file_1(const int fd, t_fil **head)
{
	t_fil	*lst;

	if (!(*head))
		return (*head = new_file_1(fd));
	lst = *head;
	while (lst->next && lst->fd != fd)
		lst = lst->next;
	if (lst->fd == fd)
		return (lst);
	else
		return (lst->next = new_file_1(fd));
}

static int	str_divide_1(char **str, char **line)
{
	char	*new;
	char	*div;

	*line = ft_strsubchr_1(*str, '\n');
	if (!(*line))
		return (-1);
	div = ft_strchrs_1(*str, '\n');
	div++;
	if (!ft_strlen_1(div))
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	new = ft_strdup_1(div);
	free(*str);
	*str = new;
	if (new)
		return (1);
	else
		return (-1);
}

void	less_lines_01(char *buff, size_t size, t_fil *f)
{
	char	*tmp;

	buff[size] = '\0';
	tmp = f->str;
	f->str = ft_strjoin_1(f->str, buff);
	free(tmp);
}

int	get_next_line_1(const int fd, char **line)
{
	static t_fil	*head = NULL;
	t_fil			*f;
	char			buff[BUFFER_SIZE + 1];
	size_t			size;

	f = get_file_1(fd, &head);
	if (fd < 0 || !line || read(fd, buff, 0) < 0 || !f)
		return (-1);
	while (!ft_strchrs_1(f->str, '\n'))
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (!size)
		{
			*line = f->str;
			if (!*line)
				return (0);
			f->str = NULL;
			return (1);
		}
		less_lines_01(buff, size, f);
		if (!f->str)
			return (-1);
	}
	return (str_divide_1(&(f->str), line));
}
