#!/bin/bash

# Esegue git status per ottenere il resoconto prima del commit
git status

# Chiede all'utente di inserire il messaggio del commit
echo "Insert commit message:"
read COMMIT_MESSAGE

# Esegue git add .
git add .

# Esegue git status per ottenere il resoconto prima del commit
git status

# Esegue git commit
git commit -m "$COMMIT_MESSAGE"

# Esegue git push
git push

echo "Mission complete."
