#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_list() {
    Node *list = malloc(sizeof(Node));
    list->value = 0;
    list->next = NULL;
    return list;
}

void delete_list(Node *list) {
    if (list->next) {
        Node *curr = list->next->next, *next;
        while (curr != list->next) {
            next = curr->next;
            free(curr);
            curr = next;
        }
        free(list->next);
    }
    free(list);
}

void prepend(Node *list, int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = list->next;
    list->next = node;
    ++(list->value);
}

void append(Node *list, int value) {
    Node *node = malloc(sizeof(Node)), *curr = list;
    node->value = value;
    node->next = NULL;
    for (; curr->next; curr = curr->next);
    curr->next = node;
    ++(list->value);
}

void insert(Node *list, int index, int value) {
    Node *curr = list->next, *prev = list;
    for (; curr && index > 0; --index) {
        prev = curr;
        curr = curr->next;
    }
    if (index == 0) {
        Node *node = malloc(sizeof(Node));
        node->value = value;
        node->next = curr;
        prev->next = node;
        ++(list->value);
    }
}

int pop_left(Node *list) {
    Node *old_head = list->next;
    int deleted_value = 0;
    if (old_head) {
        list->next = old_head->next;
        deleted_value = old_head->value;
        free(old_head);
        --(list->value);
    }
    return deleted_value;
}

int pop_right(Node *list) {
    Node *curr = list->next, *prev = list;
    int deleted_value = 0;
    if (!curr) return deleted_value;
    for (; curr->next; curr = curr->next) prev = curr;
    prev->next = NULL;
    deleted_value = curr->value;
    free(curr);
    --(list->value);
    return deleted_value;
}

int delete(Node *list, int index) {
    Node *curr = list->next, *prev = list;
    int deleted_value = 0;
    for (; curr->next && index > 0; --index) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        prev->next = curr->next;
        deleted_value = curr->value;
        free(curr);
        --(list->value);
    }
    return deleted_value;
}

int get_value(Node *list, int index) {
    int value = 0;
    Node *curr = list->next;
    for (; curr && index > 0; --index) curr = curr->next;
    if (curr) value = curr->value;
    return value;
}

void swap_values(Node *list, int index1, int index2) {
    Node *node1 = NULL, *node2 = NULL, *curr = list->next;
    // runs till both indices are not reached
    // i.e stops when one index is reached
    while (curr && (index1 > 0 && index2 > 0)) {
        curr = curr->next;
        --index1;
        --index2;
    }
    node1 = curr;
    // runs till any one of the indeices is not reached
    // i.e stops when the other index is reached
    while (curr && (index1 > 0 || index2 > 0)) {
        curr = curr->next;
        --index1;
        --index2;
    }
    node2 = curr;
    if (node1 != NULL && node2 != NULL) {
        int temp = node1->value;
        node1->value = node2->value;
        node2->value = temp;
    }
}

void print_list(Node *list) {
    Node *curr = list->next;
    putchar('[');
    if (!curr) {
        putchar(']');
        return;
    }
    printf("%d", curr->value);
    for (curr = curr->next; curr; curr = curr->next) printf(", %d", curr->value);
    putchar(']');
}

int count_list(Node *list) {
    int length = 0;
    Node *curr = list->next;
    for (; curr; curr = curr->next) ++length;
    return length;
}

void sort_list_ascending(Node *list) {
    for (int i = 1; i < list->value; ++i)
        for (int j = i-1; j >= 0; --j)
            if (get_value(list, i) < get_value(list, j))
                swap_values(list, i--, j);
}

void sort_list_descending(Node *list) {
    for (int i = 1; i < list->value; ++i)
        for (int j = i-1; j >= 0; --j)
            if (get_value(list, i) > get_value(list, j))
                swap_values(list, i--, j);
}
