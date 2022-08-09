/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:11:38 by lholdo            #+#    #+#             */
/*   Updated: 2021/10/25 16:11:39 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_1_H
# define GNL_1_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

typedef struct s_fil
{
	int				fd;
	char			*str;
	struct s_fil	*next;
}					t_fil;

// 2
char				*ft_strchr_1(const char *s, int c);
char				*ft_strchrs_1(const char *s, int c);
size_t				ft_strlen_1(const char *s);
char				*ft_strnew_1(size_t size);

// 1
char				*ft_strsub_1(char const *s, unsigned int start, size_t len);
char				*ft_strsubchr_1(const char *s, char c);
char				*ft_strdup_1(const char *s1);
int					less_lines_11(char const *s1, char const *s2);
char				*ft_strjoin_1(char const *s1, char const *s2);

int					get_next_line_1(const int fd, char **line);

#endif