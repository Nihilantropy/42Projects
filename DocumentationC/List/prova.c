#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>

typedef struct node {
    char *data;
    struct node *next;
}   t_list;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif


int count_tonewline(t_list *list)
{
    int i;
    int len;

    len = 0;
    while (list) //finchè il puntatore della lista punta a qualcosa
    {
        i = 0;
        while (list->data[i]) //finchè il buffer non arrivo a '\0'
        {
            if (list->data[i] == '\n') //se trovi la new line 
                return (len); //tornami la lunghezza fino al '\n'
            i++; //vai avanti
            len++; //incrementa la lunghezza
        }
        list = list->next; //scorri i nodi della lista finchè esiste, o finchè non trovi il '\n'
    }
    return (len); //non ha trovato '\n' (impossibile, il programma si sarebbe dovuto interrompere prima)
}

int found_newline(t_list *list)
{
    int i;

    while (list) //finchè il puntatore della lista punta a qualcosa
    {
        i = 0;
        while (list->data[i]) //finchè il buffer non arrivo a '\0'
        {
            if (list->data[i] == '\n') //se trovi la new line 
                return (1); //tornami 1
            i++; //vai avanti
        }
        list = list->next; //scorri i nodi della lista finchè esiste, o finchè non trovi il '\n'
    }
    return (0); //non ha trovato '\n'
}

void    create_new_node(t_list **list, char *buffer)
{
    t_list  *new_node; //crea un nuovo nodo
    t_list  *current;  //crea un nodo temporaneo per non perdere il puntatore alla testa della lista

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return ;
    new_node->data = buffer; //metto i dati dentro il nuovo nodo
    new_node->next = NULL; // lo faccio puntare a NULL (ultimo nodo)
    if (!*list)
        (*list) = new_node; // se la lista è vuota il nuovo nodo diventa la testa della lista
    else
    {
        current = *list;  //altrimenti utilizzo il nodo temporaneo per
        while (current->next) //scorrere la lista 
            current = current->next; // fino all'ultimo nodo
        current->next = new_node; //e mettere il nuovo nodo come ultimo nodo
    }
    printf("%s\n", new_node->data);
}

void    create_buffer(t_list **list, int fd)
{
    ssize_t bytes_read;
    char    *buffer;

    while (!(found_newline(*list))) //il ciclo continhua finchè la funzione non trova un '\n'
    {
        buffer = malloc(BUFFER_SIZE + 1); //alloco il giusto spazio al buffer
        if (!buffer)
        return ;
        bytes_read = read(fd, buffer, BUFFER_SIZE); //leggo BUFFER_SIZE byte dal file descriptor
        if (!bytes_read) //se non c'è niente da leggere
        {
            free(buffer); //libero il buffer
            return ; //interrompo la funzione
        }
        buffer[bytes_read] = '\0'; //chiudo il buffer per garantire il corretto trattamento in quanto stringa
        create_new_node(list, buffer); //vado a creare il primo nodo e poi tutti i nodi successivi ad ogni iterazione del ciclo
    }
}

char    *get_next_line(int fd)
{
    t_list *list; //dichiaro l'esistenza di una lista
    char    *line; //dichiaro la linea che sarà restituita

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0) 
        return (NULL);

    list = NULL; //inizializzo la lista a NULL
    create_buffer(&list, fd); //creo il buffer da inserire nella struttura dati
    if (!list)
        return (NULL);
    extract_line(&list);
        
}

int main()
{
    int fd = open("ListDataStruct.txt", O_RDONLY);
    if (fd <= 0)
        return 0;
    get_next_line(fd);
    return 0;
}