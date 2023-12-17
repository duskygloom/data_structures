#ifndef TABLE_ITEM_H
#define TABLE_ITEM_H

typedef char * keytype;
typedef int valuetype;

typedef struct Item {
    keytype key;
    valuetype value;
} Item;

Item *create_item(const keytype key, const valuetype value);
void delete_item(Item *item);
void print_item(const Item *item);

#endif
