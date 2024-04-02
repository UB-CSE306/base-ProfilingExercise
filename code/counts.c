#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "counts.h"

int * newArray(int size) {
    int * counts = malloc(size * sizeof(* counts));
    for (int i=0; i<size; i++) {
        counts[i] = 0;
    }
    return counts;
}

void printCounts(int * counts, char * functionName, char* dataFile) {
    int i;
    printf("Results from running %s(%s):\n", functionName, dataFile);
    for (i='a'; i<='z'; i++) {
        printf("counts['%c'] is %4d\n",i,counts[i-'a']);
    }
    printf("counts[other] is %4d\n",counts[i-'a']);
}

bool isLetter(char ch) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i<strlen(letters);i++) {
        if (ch == letters[i]) {
            return true;
        }
    }
    return false;
}

int * letterCounts(char * filename) {
    int * counts = calloc(27, sizeof(* counts));

    FILE *fp;
    fp = fopen(filename, "r");
    int ch = '\0';
    while ( (ch = fgetc(fp)) != EOF ) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            counts[ch-'a']++;
        }
        else {
            counts[26]++;
        }
    }
    fclose(fp);
    return counts;
}

int * letterCountsSlow(char * filename) {
    int * counts = newArray(27);

    FILE *fp;
    fp = fopen(filename, "r");
    int ch = '\0';
    while ( (ch = fgetc(fp)) != EOF ) {
        if (isalpha(ch)) {
            ch = (tolower(ch));
            int index = 'a';
            while (index < ch) {
                index++;
            }
            counts[index-'a']++;
        }
        else {
            counts[26]++;
        }
    }
    fclose(fp);
    return counts;
}

int * letterCountsGlacial(char * filename) {
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int * counts = newArray(27);

    for (int i=0; i<strlen(letters); i++) {
        FILE *fp;
        fp = fopen(filename, "r");
        int ch = '\0';
        while ( (ch = fgetc(fp)) != EOF ) {
            ch = tolower(ch);
            if (ch == letters[i]) {
                counts[i]++;
            }
        }
        fclose(fp);
    }

    FILE *fp;
    fp = fopen(filename, "r");
    int ch = '\0';
    while ( (ch = fgetc(fp)) != EOF ) {
        ch = tolower(ch);
        if (!isLetter(ch)) {
            counts[26]++;
        }
    }
    fclose(fp);

    return counts;
}

