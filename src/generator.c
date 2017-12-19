/**
 * Source file of anagram generator
 * @file generator.c
 * @author Jakub Majzlik
 * @version 1.0
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "generator.h"

bool generate_anagram(char **word)
{
    int word_length = strlen(*word);
    char *anagram = malloc(sizeof(char) * (word_length + 1));
    if(anagram == NULL)
    {
        free(*word);
        fprintf(stderr, "Coudn't alloc memory.");
        return false;
    }
    bool used_chars[word_length];
    srand((unsigned)time(NULL));
    for(int i = 0; i < word_length; i++)
    {
        while(true)
        {
            int index = rand()%word_length;
            if(!used_chars[index])
            {
                used_chars[index] = true;
                anagram[i] = word[0][index];
                break;
            }
        }
    }
    anagram[word_length] = '\0';
    free(*word);
    *word = anagram;
    
    return true;
}
