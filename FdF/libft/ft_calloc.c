/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:12:13 by lholdo            #+#    #+#             */
/*   Updated: 2021/10/25 16:12:14 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	mult;
	void	*str;

	mult = count * size;
	str = malloc(mult);
	if (!(str))
		return (NULL);
	ft_memset(str, 0, mult);
	return (str);
}
