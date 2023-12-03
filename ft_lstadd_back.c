#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;
    if((last = ft_lstlast((*lst))) == NULL)
        (*lst) = new;
    else
        last->next = new;
}
