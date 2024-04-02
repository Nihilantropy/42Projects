#!/bin/bash

# Funzione per cercare e contare i file .DS_Store
find_and_count_ds_store() {
    local folder="$1"
    local ds_store_count=$(find "$folder" -name ".DS_Store" | wc -l)

    if [ "$ds_store_count" -gt 0 ]; then
        echo "Trovati $ds_store_count file .DS_Store in:"
        find "$folder" -name ".DS_Store"
        return 0
    else
        echo "Nessun file .DS_Store individuato."
        return 1
    fi
}

# Funzione per eliminare i file .DS_Store
delete_ds_store() {
    local folder="$1"

    find "$folder" -name ".DS_Store" -exec rm -f {} \;
    echo "File .DS_Store eliminati con successo."
}

# Chiedi all'utente di inserire il percorso della cartella o digitare 'here', 'uphere' o 'upuphere'
read -p "Inserisci il percorso della cartella, oppure digita 'here', 'uphere' o 'upuphere': " folder_path_input

# Se l'utente ha inserito 'here', utilizza il percorso corrente
# Se ha inserito 'uphere', utilizza il percorso della cartella padre
# Se ha inserito 'upuphere', utilizza il percorso della cartella nonna
if [ "$folder_path_input" = "here" ]; then
    folder_path=$(pwd)
elif [ "$folder_path_input" = "uphere" ]; then
    folder_path=$(dirname "$(pwd)")
elif [ "$folder_path_input" = "upuphere" ]; then
    folder_path=$(dirname "$(dirname "$(pwd)")")
else
    folder_path="$folder_path_input"
fi

# Controlla se il percorso inserito è valido
if [ ! -d "$folder_path" ]; then
    echo "Il percorso inserito non è valido o non esiste."
    exit 1
fi

# Cerca e conta i file .DS_Store
if ! find_and_count_ds_store "$folder_path"; then
    exit 1
fi

# Chiedi all'utente se vuole eliminarli
read -p "Vuoi eliminare i file .DS_Store? (y/n): " choice

if [ "$choice" = "y" ]; then
    # Elimina i file .DS_Store
    delete_ds_store "$folder_path"
    echo "Operazione completata."
else
    echo "Nessun file eliminato. Operazione annullata."
fi
