#include "libft.h"
#include <stdlib.h>

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
		del((t_list *)lst->content);
	free(lst);
}