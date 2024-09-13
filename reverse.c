//Valeria Ballestero Ortiz - CC 1001229543
//Isaac Esteban Uribe Jaramillo - CC 1007240624
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    // Create an array with determinated rows te determinate the lines' number contained into the text
    FILE *input_file, *output_file;
    int count_lines = 0;
    char rows[100][MAX_LINE_LENGTH];
    char *line;

    // Determinate the number of args cointained in the atribute "argc"  

    // if there's an arg, the user is allowed to write in console, later inverts this  content and shows it to console
    if (argc == 1) {
        input_file = stdin;
        output_file = stdout;
    // if ther are two args, it reads the archive .txt and reverse its content in console
    } else if (argc == 2) {
        input_file = fopen(argv[1], "r");
        output_file = stdout;
    // if there are three args, it reads the archive .txt and saves the reversed text in a file named in the second arg "argc"
    } else if (argc == 3) {
        input_file = fopen(argv[1], "r");
        output_file = fopen(argv[2], "w");
    } else {
        fprintf(stderr, "Uso: %s [archivo_entrada] [archivo_salida]\n", argv[0]);
        return 1;
    }

    // Read the input lines into the file .txt
    while ((line = fgets(rows[count_lines], MAX_LINE_LENGTH, input_file)) != NULL) {
        rows[count_lines][strcspn(rows[count_lines], "\n")] = '\0';  
        count_lines++;
    }

    // Write the reversed lines into the output file .txt
    for (int i = count_lines - 1; i >= 0; i--) {
        fprintf(output_file, "%s\n", rows[i]);
    }

    // Close all files
    if (argc > 2) {
        fclose(output_file);
    }

    return 0;
}
