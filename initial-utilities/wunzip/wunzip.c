#include <stdio.h>

int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }

    FILE *fp = NULL;
    int index = 1;
    int num_buffer;
    char char_buffer;

    while (index < argc) {

        fp = fopen(argv[index], "r");
        if (fp == NULL)
        {
            printf("wunzip: cannot open file\n");
            return 1;
        }

        while ((fread(&num_buffer, 4, 1, fp) == 1) && (fread(&char_buffer, 1, 1, fp) == 1))
        {
            for (int i = 0; i < num_buffer; i++)
            {
                printf("%c", char_buffer);
            }
        }
        fclose(fp);
        index++;
    }

    return 0;
}

