/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaya <bmaya@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:13:26 by bmaya             #+#    #+#             */
/*   Updated: 2021/10/18 16:13:27 by bmaya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*piece;

	piece = (t_list *)malloc(sizeof(piece));
	if (!piece)
		return (NULL);
	piece->content = content;
	piece->next = NULL;
	return (piece);
}
