#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// creation and deletion

Node *create_list() {
    Node *list = malloc(sizeof(Node));
    list->value = 0;
    list->next = NULL;
    return list;
}

void delete_list(Node *list) {
    Node *curr = list, *next;
    while (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }
}

// traversal

void print_list(Node *list) {
    Node *curr = list->next;
    while (curr) {
        printf("%d ", curr->value);
        curr = curr->next;
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
    node->next = list->next;
    list->next = node;
}

void append(Node *list, int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    Node *curr = list;
    while (curr->next) curr = curr->next;
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
        node->next = curr->next;
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
        list->next = next;
    }
    return value;
}

int pop_right(Node *list) {
    int value = 0;
    Node *curr = list, *prev = NULL;
    while (curr->next) {
        prev = curr;
        curr = curr->next;
    }
    if (prev) {
        value = curr->value;
        free(curr);
        prev->next = NULL;
    }
    return value;
}

int delete(Node *list, int index) {
    int value = 0;
    ++index;        // because starting from list and not head
    Node *curr = list, *prev = NULL;
    while (curr->next && index > 0) {
        prev = curr;
        curr = curr->next;
        --index;
    }
    if (prev && index == 0) {
        value = curr->value;
        Node *next = curr->next;
        free(curr);
        prev->next = next;
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
