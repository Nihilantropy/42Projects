#include "get_next_line_bonus.h"

int len_to_newline(t_list *list)
{
    int i;
    int len;

    while (list)
    {
        i = 0;
        while (list->data[i])
        {
            if (list->data[i] == '\n')
            {
                len++;
                return(len);
            }
            i++;
            len++;
        }
        list = list->next;
    }
    return (len);
}

int find_newline(t_list *list)
{
    int i;

    while (list)
    {
        i = 0;
        while (list->data[i] && i < BUFFER_SIZE)
        {
            if (list->data[i] == '\n')
                return (1);
            i++;
        }
        list = list->next;
    }
    return (0);
}

void    cpy_nodes(char *str, t_list *list)
{
    int i;
    int j;

    j = 0;
    while (list)
    {
        i = 0;
        while (list->data[i])
        {
            if (list->data[i] == '\n')
            {
                str[j++] = list->data[i];
                str[j] = '\0';
                return ;
            }
            str[j++] = list->data[i++];
        }
        list = list->next;
    }
    str[j] = '\0';
    return ;
}

t_list    *find_last_node(t_list *list)
{
    if (!list)
        return (NULL);
    while (list->next)
        list = list->next;
    return(list);
}

void clean_list(t_list **list, t_list *new_head, char *buffer)
{
    t_list *temp;

    if (!*list)
        return ;
    while (*list)
    {
        temp = (*list)->next;
        free((*list)->data);
        free(*list);
        *list = temp;
    }
    list = NULL;
    if (new_head->data[0])
        (*list) = new_head;
    else
    {
        free(buffer);
        free(new_head);
    }
}