#include "get_next_line_bonus.h"

int main(void) {
    int fds[3];
    char *line;
    int i;

    // Apertura dei file e memorizzazione dei loro file descriptor
    fds[0] = open("prova1.txt", O_RDONLY);
    fds[1] = open("prova2.txt", O_RDONLY);
    fds[2] = open("prova3.txt", O_RDONLY);

    // Controlla se tutti i file sono stati aperti correttamente
    for (i = 0; i < 3; i++) {
        if (fds[i] < 0) {
            perror("Error opening file");
            // Chiudi tutti i file aperti fino ad ora prima di uscire
            for (int j = 0; j <= i; j++) {
                if (fds[j] >= 0) {
                    close(fds[j]);
                }
            }
            return EXIT_FAILURE;
        }
    }
    printf("contenuto 1:%s\n", line = get_next_line(fds[0]));
    printf("contenuto 2:%s\n", line = get_next_line(fds[1]));
    printf("contenuto 3:%s\n", line = get_next_line(fds[2]));
    printf("contenuto 1.1:%s\n", line = get_next_line(fds[0]));
    printf("contenuto 2.1:%s\n", line = get_next_line(fds[1]));
    printf("contenuto 3.1:%s\n", line = get_next_line(fds[2]));
    // Leggi e stampa il contenuto di ogni file utilizzando get_next_line

    close(fds[i]); // Chiudi il file descriptor quando hai finito

    return 0;
}