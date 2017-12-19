/**
 * Header file of list structure
 * @file list.h
 * @author Jakub Majzlik
 * @version 1.0
 */

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/**
 * @brief Structure of list item
 * 
 */
typedef struct listitem
{
    char *data;
    struct listitem *lptr;
    struct listitem *rptr;
}LItem;

/**
 * @brief Structure of list
 * 
 */
typedef struct
{
    LItem *first;
    LItem *last;
    LItem *act;
}Tlist;

/**
 * @brief Initializing the list
 * 
 * @param list List
 */
void list_init(Tlist *list);

/**
 * @brief Moves activity to next item in the list
 * 
 * @param list List
 */
void list_succ(Tlist *list);

/**
 * @brief Inserts new item to the list
 * 
 * @param list List
 * @param word Item
 */
bool list_insert(Tlist *list, char *word);

/**
 * @brief Disposes list
 * 
 * @param list List
 */
void list_dispose(Tlist *list);

/**
 * @brief Checks, if the list is empty
 * 
 * @param list List
 * @return true Is empty
 * @return false Is not empty
 */
bool is_list_empty(Tlist *list);

/**
 * @brief Gets length of he list
 * 
 * @param list List
 * @return int Length of the list
 */
int list_length(Tlist *list);

/**
 * @brief Gets data from the list at secific index
 * 
 * @param list List
 * @param index Index
 * @return char* Data
 */
char *list_get_data(Tlist *list, int index);

#endif