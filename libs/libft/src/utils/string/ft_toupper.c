/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:56:02 by jv                #+#    #+#             */
/*   Updated: 2022/04/10 15:57:16 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int C)
{
	if (C >= 97 && C <= 122)
		return (C - 32);
	return (C);
}