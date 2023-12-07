#include "table_item.h"

/**
 * @note
 * Copies key and value to item so it is 
 * fine to free the original key and value
*/
Item *create_item(const keytype key, const valuetype value)
{
    Item *item = malloc(sizeof(Item));
    item->key = calloc(strlen(key)+1, sizeof(char));
    strcpy(item->key, key);
    item->value = value;
    return item;
}

void delete_item(Item *item)
{
    if (item) {
        if (item->key) free(item->key);
        free(item);
    }
}

void print_item(const Item *item)
{
    printf("%s - %d\n", item->key, item->value);
}
