#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    t_list *last;

    if((last = malloc(sizeof(t_list))) == NULL)
        return NULL;
    last = lst;
    if (last == NULL)
        return NULL;
    if (last->next == NULL)
        return (last);
    while (last != NULL)
    {
        if(last->next->next == NULL)
        {
            last = last->next;
            return(last);
        }
        last = last->next;
    }
    return (last);
}