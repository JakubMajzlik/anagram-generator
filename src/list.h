
#ifndef LIST_H
#define LIST_H

#include <stdbool.h>


/**
 * @brief Struktura polozky zoznamu
 * 
 */
typedef struct listitem
{
    char *data;
    struct listitem *lptr;
    struct listitem *rptr;
}LItem;

/**
 * @brief Struktura zoznamu instrukcii
 * 
 */
typedef struct
{
    LItem *first;
    LItem *last;
    LItem *act;
}Tlist;

/**
 * @brief Funkcia inicializuje zoznam instrukcii
 * 
 * @param list Zoznam, ktory chceme inicializovat
 */
void list_init(Tlist *list);

/**
 * @brief Funkcia posunie aktivitu o jednu polozku doprava
 * 
 * @param list Zoznam, v ktorom chceme aktivitu posunut
 */
void list_succ(Tlist *list);

/**
 * @brief Funkcia vlozi instrukciu na koniec zoznamu
 * 
 * @param list Zoznam, do ktoreho chceme vlozit instrukciu
 * @param inst Instrukcia, ktoru chceme vlozit
 */
bool list_insert(Tlist *list, char *word);

/**
 * @brief 
 * 
 * @param list 
 */
void list_dispose(Tlist *list);

/**
 * @brief Funkcia skontroluje, ci je zoznam prazdny
 * 
 * @param list Zoznam, ktory chceme skontrolovat
 * @return true Vrati true ak je zoznam prazdny
 * @return false Vrati false ak zoznam nie je prazdny
 */
bool is_list_empty(Tlist *list);

int list_length(Tlist *list);

char *list_get_data(Tlist *list, int index);


#endif