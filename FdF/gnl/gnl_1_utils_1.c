/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_1_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lholdo <lholdo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:11:31 by lholdo            #+#    #+#             */
/*   Updated: 2021/10/25 16:11:32 by lholdo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_1.h"

char	*ft_strsub_1(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s || start + len > ft_strlen_1(s))
		return (NULL);
	result = ft_strnew_1(len);
	if (result)
	{
		while (len)
		{
			result[i++] = s[start++];
			len--;
		}
		result[i] = '\0';
	}
	return (result);
}

char	*ft_strsubchr_1(const char *s, char c)
{
	char	*ptr;

	ptr = ft_strchrs_1(s, c);
	if (!(ptr))
		return (NULL);
	return (ft_strsub_1(s, 0, ptr - s));
}

char	*ft_strdup_1(const char *s1)
{
	size_t	i;
	char	*result;

	result = ft_strnew_1(ft_strlen_1(s1));
	if (result)
	{
		i = 0;
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}

int	less_lines_11(char const *s1, char const *s2)
{
	int	tmp;
	int	tmp1;

	if (s1)
		tmp = ft_strlen_1(s1);
	else
		tmp = 0;
	if (s2)
		tmp1 = ft_strlen_1(s2);
	else
		tmp1 = 0;
	tmp = tmp + tmp1;
	return (tmp);
}

char	*ft_strjoin_1(char const *s1, char const *s2)
{
	char	*result;
	char	*start;
	int		tmp;

	if (!s1 && !s2)
		return (NULL);
	tmp = less_lines_11(s1, s2);
	result = ft_strnew_1(tmp);
	start = result;
	if (start)
	{
		if (s1)
			while (*s1)
				*result++ = *s1++;
		if (s2)
			while (*s2)
				*result++ = *s2++;
		*result = '\0';
	}
	return (start);
}
