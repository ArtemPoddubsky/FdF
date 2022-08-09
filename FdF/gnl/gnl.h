/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:11:47 by lholdo            #+#    #+#             */
/*   Updated: 2021/10/25 16:11:48 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE 4096

typedef struct s_file
{
	int				fd;
	char			*str;
	struct s_file	*next;
}					t_file;

// 2
char				*ft_strchr(const char *s, int c);
char				*ft_strchrs(const char *s, int c);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);

// 1
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsubchr(const char *s, char c);
char				*ft_strdup(const char *s1);
int					less_lines_1(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);

int					get_next_line(const int fd, char **line);

#endif