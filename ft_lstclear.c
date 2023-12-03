#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp_frt;
    t_list	*temp_bck;

	if (!lst)
		return ;
	temp_frt = (*lst);
	temp_bck = (*lst);
	while (temp_bck)
	{
		temp_frt = temp_frt->next;
		del(temp_bck->content);
		free(temp_bck);
		temp_bck = temp_frt;
	}
	(*lst) = 0;
}
