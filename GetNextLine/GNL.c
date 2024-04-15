#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

typedef struct node {
    char *data;
    struct node *next;
}   t_list;

static int count_to_newline(t_list *list)
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
            {
                len++; //includi il '\n'
                return (len); //tornami la lunghezza fino al '\n'
            }
            i++; //vai avanti
            len++; //incrementa la lunghezza
        }
        list = list->next; //scorri i nodi della lista finchè esiste, o finchè non trovi il '\n'
    }
    return (len); //non ha trovato '\n'
}

static void    cpy_nodes(char *str, t_list *list)
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
    str[j] = '\0'; //chiudo la string anche se non ho trovato il '\n' (quindi siamo alla fine della lettura)
    return ;
}

static char *extract_line(t_list *list)
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

static int found_newline(t_list *list)
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

t_list    *find_last_node(t_list *list)
{
    if (!list)
        return (NULL);
    while (list->next) //finchè ci sono nodi
        list = list->next; //scorro la lista
    return (list); //ritorno l'ultimo nodo
}

static void    create_new_node(t_list **list, char *buffer)
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
        current = find_last_node(*list); //ritorna un puntatore all'ultimo nodo della lista
        current->next = new_node; //e mettere il nuovo nodo come ultimo nodo
    }
}

static void    create_buffer(t_list **list, int fd)
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

static void    clean_list(t_list **list, t_list *new_head, char *buffer)
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

static void    polish_list(t_list **list)
{
    int i;
    int j;
    char *buffer; //array dove contenere il buffer letto restande dopo il '\n'
    t_list *last_node; //ultimo nodo della lista dove si trova il residuo
    t_list *new_head; //nodo che conterrà il residuo e diventerà la nuova testa della lista

    new_head = malloc(sizeof(t_list)); //inizializzazione nuova testa della lista
    buffer = malloc(BUFFER_SIZE + 1); //inizializzazione contenuto del nodo
    if (!new_head || !buffer)
        return ;
    i = 0; //indice per il residuo
    j = 0; //indice per il buffer
    last_node = find_last_node(*list); //vado all'ultimo nodo della lista
    while (last_node->data[i] && last_node->data[i] != '\n') //scorro l'indice i finchè non trovo '\n' o '\0'
        i++;
    while (last_node->data[i] && last_node->data[i++]) //scorro il 'data' finchè non arriva a '\0' e incremento preventivamente i, per non includere il '\n' (e per non superare le 25 righe)
        buffer[j++] = last_node->data[i]; //copio il residuo dentro il buffer. i si incrementa nella condizione
    buffer[j] = '\0'; //chiudo il buffer
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
