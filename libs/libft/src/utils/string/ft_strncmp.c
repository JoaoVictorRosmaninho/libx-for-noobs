/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:15:10 by jv                #+#    #+#             */
/*   Updated: 2024/03/23 21:25:00 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_strncmp(const char *S1, const char *S2, size_t SIZE)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *) S1;
	s2 = (unsigned char *) S2;
	while ((s1[i] == s2[i]) && s1[i] && s2[i] && (i < (SIZE - 1)))
		i++;
	return ((int)(s1[i] - s2[i]));
}
