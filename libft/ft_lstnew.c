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
