#include "libft.h"

void 	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else if (*lst != NULL)
			ft_lstlast(*lst)->next = new;
	}
}