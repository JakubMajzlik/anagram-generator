/**
 * Main file of program
 * @file main.c
 * @author Jakub Majzlik
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "list.h"
#include "generator.h"

//Colors
#define CRED  "\x1B[31m"
#define CGRN  "\x1B[32m"
#define CNRM  "\x1B[0m"

int main(int argc, char *argv[])
{
    FILE *file_with_words;

    if(argc == 1)
    {
        printf("File with words: \n");
        char path[127];
        fscanf(stdin, "%s", path);
        file_with_words = fopen(path, "r");

        if(file_with_words == NULL)
        {
            fprintf(stderr, "Coudn't open file with words.\n");
            return 1;
        }
    }
    else if(argc == 2)
    {
        file_with_words = fopen(argv[1], "r");
        if(file_with_words == NULL)
        {
            fprintf(stderr, "Coudn't open file with words.\n");
            return 1;
        }
    }
    else
    {
        fprintf(stderr, "Usage: anagramgenerator [path]\n");
        return 1;
    }

    Tlist *list = malloc(sizeof(Tlist));
    if(list == NULL)
    {
        fclose(file_with_words);
        fprintf(stderr, "internal error.\n");
        return 1;
    }
    list_init(list);

    while(!feof(file_with_words))
    {
        char word[127];
        
        if( fscanf(file_with_words, "%s\n", word) == EOF)
        {
            break;
        }
        if(!list_insert(list, word))
        {
            list_dispose(list);
            free(file_with_words);
            return 1;
        }
    }

    int number_of_words = list_length(list);
    char *input = malloc(sizeof(char)*127);
    srand((unsigned)time(NULL));
    printf("==========ANAGRAM=GENERATOR==========\n");
    do
    {
        int index = rand()%number_of_words;
        char *word_to_shuffle = malloc(sizeof(char)*127);
        strcpy(word_to_shuffle, list_get_data(list, index));
        if(!generate_anagram(&word_to_shuffle))
        {
            list_dispose(list);
            fclose(file_with_words);
            return 1;
        }
        printf("%s\n", word_to_shuffle);
        fscanf(stdin, "%s", input);
        if(strcmp(input, "end") == 0)
        {
            break;
        }
        else if(strcmp(input, list_get_data(list, index)) != 0)
        {
            printf(CRED"Wrong!!\n\n\n"CNRM);
        }
        else
        {
            printf(CGRN"Good!!\n\n\n"CNRM);
        }
        free(word_to_shuffle);
    }while(true);
    free(input);
    list_dispose(list);
    fclose(file_with_words);

    
    
    return 0;
}