#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>


typedef struct {
    
    uint8_t file_type;
    uint32_t start;
    uint32_t length;

} PieceTable;


void enable_raw_mode() {

    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

}


int main(int argc, char* argv[]) {
    FILE* fptr = NULL;

    /* Syntax error */
    if (argc > 2) {

        printf("Syntax error.\nTry 'macro <filename>' or 'macro'\nExit code: 1\n");
        return 1;

    /* Open some file */
    } else if (argc == 2) {

        printf("*debug* Opened %s.\n", argv[1]);
        fptr = fopen(argv[1], "a");

    /* Create new file */
    } else {

        printf("*debug* Openned new file.\n");
        fptr = fopen(".new_file", "w");
    }

    /* Check for file integrity */
    if (fptr == NULL) {
        printf("Failed to open a file.\nExit code: 2\n");
        return 2;
    }

    /* Disable output in console */
    enable_raw_mode();

    /* Typo */
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');

    fclose(fptr);
    return 0;
}