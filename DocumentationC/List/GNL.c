#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

#ifdef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

typedef struct node {
    char *data;
    struct node *next;
}   t_list;

int count_to_newline(t_list *list)
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

void    cpy_nodes(char *str, t_list *list)
{
    int i; //scorro il list data
    int j; //scorro la stringa str

    j = 0;
    while (list) //finchè esiste la stringa
    {
        i = 0;
        while (list->data[i] && i < BUFFER_SIZE) //finchè esiste data o i non supera il BUFFER_SIZE
        {
            if (list->data[i] == '\n') //appena trovi '\n'
            {
                str[j++] = list->data[i]; //copia il '\n'
                str[j] = '\0'; //incrementa e 
                return ;
            }
            str[j++] = list->data[i++]; //copia i dati nella stringa
        }
        list = list->next; //scorro la lista
    }
    return ;
}

void    ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    if (!s1 || !s2)
        return ;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return ;
}

char *extract_line(t_list *list)
{
    char *line;
    int len;

    len = count_to_newline(list); //conta i caratteri fino al '\n'
    line = malloc(len + 1); //alloca una stringa con lo spazio necessario
    if (!line)
        return (NULL);
    cpy_nodes(line, list); //copia i nodi della stringa letti, escluso l'eccesso del buffer, nella stringa
    return(line); //ritorna la stringa
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

t_list    *find_last_node(t_list **list)
{
    t_list *current;

    if (!*list)
        return (NULL);
    current = *list; //salvo il pointer alla testa attuale
    while (current->next) //finchè ci sono nodi
        current = current->next; //scorro la lista
    return (current); //ritorno l'ultimo nodo
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
    else //altrimenti
    {
        current = find_last_node(list); //ritorna un puntatore all'ultimo nodo della lista
        current->next = new_node; //e mettere il nuovo nodo come ultimo nodo
    }
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

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    clean_list(t_list **list, t_list *new_head, char *buffer)
{
    t_list  *temp; //puntatore dove salvare l'indirizzo del nodo 'next', ovvero il successivo

    if (!*list)
        return ;
    while (*list)
    {
        temp = (*list)->next; //salvo l'indirizzo del prossimo nodo
        free((*list)->data); //libero il 'data' del nodo corrente
        free(*list); //libero l'indirizzo del nodo corrente
        *list = temp; //vado al nodo successivo
    }
    *list = NULL; //reimposto la lista a NULL
    if (new_head->data[0]) //se il residuo esiste
        *list = new_head; //diventa il nodo alla testa della lista
    else //altrimenti
    {
        free(buffer); //libero il buffer allocato
        free(new_head); //libero il puntatore al nodo
    }
}

void    polish_list(t_list **list)
{
    int i;
    int j;
    char *buffer; //array dove contenere il buffer letto restande dopo il '\n'
    t_list *last_node; //ultimo nodo della lista dove si trova il residuo
    t_list *new_head; //nodo che conterrà il residuo e diventerà la nuova testa della lista

    i = 0;
    last_node = find_last_node(list);
    while (last_node->data[i] && last_node->data[i] != '\n') //arrivo fino al '\n' o al '\0'
        i++;
    j = ft_strlen(last_node->data + i); //trovo l'esatta lunghezza del residuo
    buffer = malloc(j + 1); //alloco lo spazio necessario per il residuo
    new_head = malloc(sizeof(t_list)); //creo la nuova testa della lista
    if (!buffer || !new_head)
        return ;
    ft_strcpy(buffer, last_node->data + i + 1); //copio solo il residio nel buffer + lo spazio per il '\0'
    new_head->data = buffer; //metto il residuo dentro il 'data' della nuova testa
    new_head->next = NULL; //lo imposto come unico nodo della lista
    clean_list(list, new_head, buffer); //pulisco la lista e imposto la nuova testa
}

char    *get_next_line(int fd)
{
    static t_list *list; //dichiaro l'esistenza di una lista statica
    char    *line; //dichiaro la linea che sarà restituita

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0) 
        return (NULL);
    create_buffer(&list, fd); //creo il buffer da inserire nella struttura dati
    if (!list)
        return (NULL);
    line = extract_line(list);
    polish_list(&list);
    return (line);
}

int main()
{
    char *line;

    int fd = open("ListDataStruct.txt", O_RDONLY);
    if (fd <= 0)
        return 0;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}