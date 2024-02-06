#!/bin/bash

# Esegue git status per ottenere il resoconto prima del commit
git status

# Verifica se ci sono modifiche non staged o non committate
if ! git diff-index --quiet HEAD --; then
    # Chiede all'utente di inserire il messaggio del commit se ci sono modifiche
    echo "Inserisci il messaggio del commit:"
    read COMMIT_MESSAGE

    # Esegue git add per aggiungere tutte le modifiche
    git add .

    # Mostra lo stato attuale dopo l'aggiunta
    git status

    # Esegue git commit
    git commit -m "$COMMIT_MESSAGE"
else
    echo "Nessuna modifica da committare."
fi

# Controlla se c'è qualcosa da pushare
NEEDS_PUSH=$(git cherry -v)
if [ -z "$NEEDS_PUSH" ]; then
    echo "Tutto è già aggiornato. Niente da pushare."
else
    # Esegue git push
    git push
    echo "Mission complete."
fi
