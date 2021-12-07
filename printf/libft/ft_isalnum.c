/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:11:47 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/18 16:11:48 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int simb)
{
	if ((simb >= 'a' && simb <= 'z') || (simb >= 'A' && simb <= 'Z') \
			|| (simb >= '0' && simb <= '9'))
		return (1);
	else
		return (0);
}