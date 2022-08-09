/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_1_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:11:33 by lholdo            #+#    #+#             */
/*   Updated: 2021/10/25 16:11:34 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_1.h"

char	*ft_strchr_1(const char *s, int c)
{
	char	*ptr;
	char	sym;

	ptr = (char *)s;
	sym = (char)c;
	while (*ptr && !(*ptr == sym))
		ptr++;
	if (*ptr == sym)
		return (ptr);
	else
		return (NULL);
}

char	*ft_strchrs_1(const char *s, int c)
{
	if (!s)
		return (NULL);
	return (ft_strchr_1(s, c));
}

size_t	ft_strlen_1(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strnew_1(size_t size)
{
	return ((char *) malloc(sizeof(char) * (size + 1)));
}
