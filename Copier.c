#include <stdio.h>
#include <stdlib.h>

int main(int argn, char* argv[]) {
    FILE *file1, *file2;
    char c;

    if (argn != 3){
        printf("[!] Wrong argument count.\nUsage: Copier <Source File> <Destination File>\n");
        exit(0);
    }

    file1 = fopen(argv[1], "r");
    if (file1 == NULL){
        printf("[!] Cannot read file %s\n", argv[1]);
        exit(0);
    }

    file2 = fopen(argv[2], "w+");
    if(file2 == NULL){
        printf("[!] Cannot read file %s\n", argv[2]);
        exit(0);
    }

    c = fgetc(file1);
    double percentage = 0.00;
    while (c != EOF)
    {
        fputc(c, file2);
        c = fgetc(file1);
        
        while (percentage <= 1.00) {
        printProgress(percentage);
        percentage = percentage + 0.001;
        }
    }

    printf("\nFile %s copied to file %s\n", argv[1], argv[2]);
    fclose(file1);
    fclose(file2);
}

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

void printProgress(double percentage) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
    usleep(2000);
}