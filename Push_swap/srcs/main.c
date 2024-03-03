#include <stdio.h>  // Per la funzione printf
#include <stdlib.h> // Per la funzione malloc
#include "../include/push_swap.h"

// Inizializza la lista circolare doppia con un nodo vuoto
dct_list *init_list(void)
{
    dct_list *list = malloc(sizeof(dct_list));
    if (!list)
        return NULL;
    list->data = 0;
    list->next = list; // Puntatore al prossimo nodo punta a se stesso
    list->prev = list; // Puntatore al nodo precedente punta a se stesso
    return list;
}

// Crea un nuovo nodo vuoto
dct_list *create_new_node(void)
{
    dct_list *new_node = malloc(sizeof(dct_list));
    if (!new_node)
        return NULL;
    new_node->data = 0; // Inizializza i dati del nodo a 0
    new_node->next = NULL; // Inizializza il puntatore al prossimo nodo a NULL
    new_node->prev = NULL; // Inizializza il puntatore al nodo precedente a NULL
    return new_node;
}

// Aggiunge un nuovo nodo alla fine della lista circolare doppia
void add_node_back(dct_list *list, dct_list *new_node)
{
    if (!list || !new_node)
        return;
    
    // Trova l'ultimo nodo nella lista
    dct_list *last_node = list->prev;

    // Imposta i puntatori del nuovo nodo
    new_node->next = list;    // Il puntatore al prossimo nodo punta al primo nodo
    new_node->prev = last_node; // Il puntatore al nodo precedente punta all'ultimo nodo

    // Aggiorna i puntatori del primo e dell'ultimo nodo
    list->prev = new_node;   // Il puntatore al nodo precedente del primo nodo punta al nuovo nodo
    last_node->next = new_node; // Il puntatore al prossimo nodo dell'ultimo nodo punta al nuovo nodo
}

// Stampa i dati di tutti i nodi nella lista circolare doppia
void print_list(dct_list *list)
{
    if (!list)
        return;

    dct_list *current = list;
    do {
        ft_printf("%d ", current->data);
        current = current->next;
    } while (current != list);
    ft_printf("\n");
}

// Libera la memoria allocata dalla lista circolare doppia e imposta il puntatore della lista a NULL
void free_list(dct_list **list)
{
    if (!list || !*list)
        return;

    dct_list *current = (*list)->next; // Inizia dal primo nodo effettivo
    dct_list *next_node;

    while (current != *list) { // Continua finché non si torna al nodo iniziale
        next_node = current->next; // Salva il riferimento al prossimo nodo
        free(current);             // Libera il nodo corrente
        current = next_node;       // Passa al prossimo nodo
    }

    free(*list); // Libera il nodo iniziale
    *list = NULL; // Imposta il puntatore della lista a NULL
}

int main()
{
    dct_list *list;
    dct_list *new_node;

    // Inizializza la lista circolare doppia
    list = init_list();

    // Aggiunge alcuni nodi alla lista
    for (int i = 1; i <= 5; i++) {
        new_node = create_new_node();
        new_node->data = i;
        add_node_back(list, new_node);
    }

    // Stampa la lista
    ft_printf("Lista circolare doppia: ");
    print_list(list);

    // Libera la memoria allocata dalla lista
    free_list(&list); // Passa il primo nodo effettivo poiché list è il nodo vuoto iniziale

    // Libera il nodo iniziale vuoto
    free(list);

    return 0;
}
