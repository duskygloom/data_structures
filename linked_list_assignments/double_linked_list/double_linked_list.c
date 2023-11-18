#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

// creation and deletion

Node *create_list() {
    Node *list = malloc(sizeof(Node));
    list->value = 0;
    list->prev = NULL;
    list->next = NULL;
    return list;
}

void delete_list(Node *list) {
    Node *next, *curr = list;
    while (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }
}

// traversal

void print_list(Node *list) {
    Node *curr = list;
    printf("Forward:");
    while (curr->next) {
        printf(" %d", curr->next->value);
        curr = curr->next;
    }
    putchar('\n');
    printf("Backward:");
    while (curr->prev) {
        printf(" %d", curr->value);
        curr = curr->prev;
    }
    putchar('\n');
}

int count_list(Node *list) {
    int count = 0;
    Node *curr = list->next;
    while (curr) {
        ++count;
        curr = curr->next;
    }
    return count;
}

// insertion

void prepend(Node *list, int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->prev = list;
    node->next = list->next;
    if (list->next) list->next->prev = node;
    list->next = node;
}

void append(Node *list, int value) {
    Node *node = malloc(sizeof(Node)), *curr = list;
    node->value = value;
    node->next = NULL;
    while (curr->next) curr = curr->next;
    node->prev = curr;
    curr->next = node;
}

void insert(Node *list, int index, int value) {
    Node *curr = list;
    while (curr->next && index > 0) {
        curr = curr->next;
        --index;
    }
    if (index == 0) {
        Node *node = malloc(sizeof(Node));
        node->value = value;
        node->prev = curr;
        node->next = curr->next;
        if (curr->next) curr->next->prev = node;
        curr->next = node;
    }
}

// deletion

int pop_left(Node *list) {
    int value = 0;
    if (list->next) {
        Node *next = list->next->next;
        value = list->next->value;
        free(list->next);
        if (next) next->prev = list;
        list->next = next;
    }
    return value;
}

int pop_right(Node *list) {
    int value = 0;
    Node *curr = list;
    while (curr->next) curr = curr->next;
    if (curr->prev) {
        value = curr->value;
        curr->prev->next = NULL;
        free(curr);
    }
    return value;
}

int delete(Node *list, int index) {
    int value = 0;
    ++index;        // because starting from list and not head
    Node *curr = list;
    while (curr->next && index > 0) {
        curr = curr->next;
        --index;
    }
    if (curr->prev && index == 0) {
        value = curr->value;
        Node *next = curr->next;
        free(curr);
        curr->prev->next = next;
        if (next) next->prev = curr->prev;
    }
    return value;
}

int *get_value_address(Node *list, int index) {
    Node *curr = list;
    ++index;
    while (curr->next && index > 0) {
        curr = curr->next;
        --index;
    }
    if (index == 0) return &(curr->value);
    return NULL;
}

void ascending_sort(Node *list) {
    int *ith, *jth, temp;
    for (int i = 1; i < count_list(list); ++i)
        for (int j = i-1; j >= 0; --j) {
            ith = get_value_address(list, i);
            jth = get_value_address(list, j);
            if (*ith < *jth) {
                temp = *ith;
                *ith = *jth;
                *jth = temp;
                --i;
            }
        }
}

void descending_sort(Node *list) {
    int *ith, *jth, temp;
    for (int i = 1; i < count_list(list); ++i)
        for (int j = i-1; j >= 0; --j) {
            ith = get_value_address(list, i);
            jth = get_value_address(list, j);
            if (*ith > *jth) {
                temp = *ith;
                *ith = *jth;
                *jth = temp;
                --i;
            }
        }
}

