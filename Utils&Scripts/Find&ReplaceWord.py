import sys

def replace_word_in_file(file_path, old_word, new_word):
    try:
        with open(file_path, 'r') as file:
            content = file.read()

        # Effettua la sostituzione della parola nel contenuto del file
        new_content = content.replace(old_word.lower(), new_word.lower())
        new_content = new_content.replace(old_word.capitalize(), new_word.capitalize())
        new_content = new_content.replace(old_word.upper(), new_word.upper())

        # Scrivi il nuovo contenuto nel file
        with open(file_path, 'w') as file:
            file.write(new_content)

        print(f"Sostituzione di '{old_word}' con '{new_word}' completata con successo.")
    except FileNotFoundError:
        print("File non trovato.")
    except Exception as e:
        print(f"Si è verificato un errore: {e}")


def main():
    if len(sys.argv) != 4:
        print("Utilizzo: python script.py <file_path> <old_word> <new_word>")
        return

    file_path = sys.argv[1]
    old_word = sys.argv[2]
    new_word = sys.argv[3]

    # Esegui la sostituzione della parola nel file
    replace_word_in_file(file_path, old_word, new_word)


if __name__ == "__main__":
    main()
