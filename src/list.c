#include "list.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void list_init(Tlist *list)
{
    list->act = list->last = list->first = NULL;
}


void list_succ(Tlist *list)
{
    if(!is_list_empty(list))
    {
        if(list->act->rptr != NULL)
        {
            list->act = list->act->rptr;
        }
        else
        {
            list->act= NULL;
        }
    }
}

bool list_insert(Tlist *list, char *data)
{
    LItem *new_item = malloc(sizeof(LItem));
    if(new_item == NULL)
    {
        fprintf(stderr, "Coudn't alloc memory.");
        return false;
    }
    new_item->data = malloc(sizeof(char) * (strlen(data)+1));
    if(new_item->data == NULL)
    {
        fprintf(stderr, "Coudn't alloc memory.");
        return false;
    }
    strcpy(new_item->data, data);
    if(is_list_empty(list))
    {
        list->first = list->last = new_item;
    }
    else
    {
        list->last->rptr = new_item;
        new_item->lptr = list->last;
        list->last = new_item;
        new_item->rptr = NULL;

    }
    return true;
}

void list_dispose(Tlist *list)
{
    LItem *item = list->first;

    if(item != NULL)
    {
        while(item->rptr != NULL)
        {
            item = item ->rptr;
            free(item->lptr);
        }
        free(item);
        list->first = NULL;
        list->last = NULL;
        list->act = NULL;
    }
}

bool is_list_empty(Tlist *list)
{
    return list->first == NULL;
}

int list_length(Tlist *list)
{
    LItem *temp = list->act;
    list->act = list->first;

    int item_counter = 0;

    while(list->act != NULL)
    {
        item_counter++;
        list_succ(list);
    }

    list->act = temp;

    return item_counter;
}

char *list_get_data(Tlist *list, int index)
{
    if(is_list_empty(list))
    {
        return NULL;
    }
    list->act = list->first;

    for(int i = 0; i < index; i++)
    {
        list_succ(list);
    }
    return list->act->data;
}