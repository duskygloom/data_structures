#include "linked_list.h"
#include "hash_table.h"

Node *create_node(const Item *item)
{
    Node *node = malloc(sizeof(Node));
    node->item = create_item(item->key, item->value);
    node->next = NULL;
    return node;
}

bool insert_node(Node *head, Node *node)
{
    while (head->next != NULL) {
        if (node->movie->name == head->movie->name)
            return false;                                   // no override
        head = head->next;
        check_collision(false);
    }
    head->next = node;
    return true;
}

bool delete_list(Node *head)
{
    Node *next;
    while (head) {
        next = head->next;
        delete_node(head);
        head = next;
    }
}
