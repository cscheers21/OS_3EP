#include <stdio.h>;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    FILE *fp = fopen(argv[3], "r");
    if (fp == NULL) {
        printf("wgrep: cannout open file\n");
        return 1;
    }

    char *line = NULL;
    size_t size = 0;

    while(getline(&line, &size, fp) != -1) {
        
    }

}