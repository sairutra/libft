#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int size;
    t_list *temp;

    size = 0;
    temp = malloc(sizeof(t_list));
    if (temp == NULL)
        return 0;
    temp = lst; 
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }
    free(temp);
    return (size);
}