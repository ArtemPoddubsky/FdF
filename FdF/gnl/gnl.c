/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:11:46 by lholdo            #+#    #+#             */
/*   Updated: 2021/10/25 16:11:47 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

void	less_lines_0(char *buff, size_t size, t_file *f)
{
	char	*tmp;

	buff[size] = '\0';
	tmp = f->str;
	f->str = ft_strjoin(f->str, buff);
	free(tmp);
}

static t_file	*new_file(const int fd)
{
	t_file	*new;

	new = (t_file *)malloc(sizeof(t_file));
	if (new)
	{
		new->fd = fd;
		new->str = NULL;
	}
	return (new);
}

static t_file	*get_file(const int fd, t_file **head)
{
	t_file	*lst;

	if (!(*head))
		return (*head = new_file(fd));
	lst = *head;
	while (lst->next && lst->fd != fd)
		lst = lst->next;
	if (lst->fd == fd)
		return (lst);
	else
		return (lst->next = new_file(fd));
}

static int	str_divide(char **str, char **line)
{
	char	*new;
	char	*div;

	*line = ft_strsubchr(*str, '\n');
	if (!(*line))
		return (-1);
	div = ft_strchrs(*str, '\n');
	div++;
	if (!ft_strlen(div))
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	new = ft_strdup(div);
	free(*str);
	*str = new;
	if (new)
		return (1);
	else
		return (-1);
}

int	get_next_line(const int fd, char **line)
{
	static t_file	*head = NULL;
	t_file			*f;
	char			buff[BUF_SIZE + 1];
	size_t			size;

	f = get_file(fd, &head);
	if (fd < 0 || !line || read(fd, buff, 0) < 0 || !f)
		return (-1);
	while (!ft_strchrs(f->str, '\n'))
	{
		size = read(fd, buff, BUF_SIZE);
		if (!size)
		{
			*line = f->str;
			if (!*line)
				return (0);
			f->str = NULL;
			return (1);
		}
		less_lines_0(buff, size, f);
		if (!f->str)
			return (-1);
	}
	return (str_divide(&(f->str), line));
}
