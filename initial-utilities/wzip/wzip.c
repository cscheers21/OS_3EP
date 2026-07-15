#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    int index = 1;
    int prev_char;
    int sent_char;
    int counter = 1;
    FILE *fp = NULL;

    while (index < argc) {
        fp = fopen(argv[index], "r");
        if (fp == NULL) {
            printf("Could not open file\n");
            return 1;
        }

        prev_char = fgetc(fp);
        if (prev_char == EOF) {
            index++;
            continue;
        }

        while (prev_char != EOF) {
            sent_char = fgetc(fp);
            if (sent_char != prev_char) {
                fwrite(&counter, sizeof(int), 1, stdout);
                fwrite(&prev_char, sizeof(char), 1, stdout);
                counter = 1;
            }
            else {
                counter++;
            }

            prev_char = sent_char;
        }
        fclose(fp);
        index++;
    }
    return 0;
}