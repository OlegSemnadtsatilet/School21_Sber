#include "libft.h"
#include <stdlib.h>

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	
	while (*lst->next != NULL)
	{
		temp = *lst->next;
		del((*lst->content);
		free(*lst);
		*lst->next = temp;
	}

}