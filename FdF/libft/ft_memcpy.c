/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:12:36 by lholdo            #+#    #+#             */
/*   Updated: 2021/10/25 16:12:37 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*to;
	char	*from;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	to = (char *)dst;
	from = (char *)src;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dst);
}
