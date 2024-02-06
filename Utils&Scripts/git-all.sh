#!/bin/bash

# Display git status to get the overview before commit
git status

# Check for unstaged or uncommitted changes
if ! git diff-index --quiet HEAD --; then
    # Ask the user to input the commit message if there are changes
    echo "Insert commit message:"
    read COMMIT_MESSAGE

    # Add all changes with git add
    git add .

    # Show the current status after adding
    git status

    # Commit the changes
    git commit -m "$COMMIT_MESSAGE"
else
    echo "No changes to commit."
fi

# Check if there is anything to push
NEEDS_PUSH=$(git cherry -v)
if [ -z "$NEEDS_PUSH" ]; then
    echo "Everything is up to date. Nothing to push."
else
    # Push the changes
    git push
    echo "Mission complete."
fi
