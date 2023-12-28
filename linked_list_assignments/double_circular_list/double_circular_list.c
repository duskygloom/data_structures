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
    Node *head = list->next;
    Node *curr = head, *next = NULL;
    if (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    while (curr && curr != head) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}

// traversal

void print_list(Node *list) {
    Node *head = list->next;
    if (!head) {
        printf("Forward: []\nBackward: []\n");
        return;
    }
    Node *curr = head;
    printf("Forward: [");
    printf("%d", curr->value);
    curr = curr->next;
    while (curr && curr != head) {
        printf(", %d", curr->value);
        curr = curr->next;
    }
    printf(" -> %d", curr->value);
    printf("]\n");
    printf("Backward: [");
    Node *tail = curr->prev;
    curr = tail;
    printf("%d", curr->value);
    curr = curr->prev;
    while (curr && curr != tail) {
        printf(", %d", curr->value);
        curr = curr->prev;
    }
    printf(" -> %d", curr->value);
    printf("]\n");
}

int count_list(Node *list) {
    int count = 0;
    Node *head = list->next;
    Node *curr = head;
    if (curr) {
        ++count;
        curr = curr->next;
    }
    while (curr && curr != head) {
        ++count;
        curr = curr->next;
    }
    return count;
}

// insertion

void prepend(Node *list, int value) {
    Node *head = list->next;
    Node *node = malloc(sizeof(Node));
    node->value = value;
    if (!head) {
        node->next = node;
        node->prev = node;
        list->next = node;
        return;
    }
    node->next = head;
    node->prev = head->prev;
    head->prev->next = node;
    head->prev = node;
    list->next = node;
}

void append(Node *list, int value) {
    Node *head = list->next;
    Node *node = malloc(sizeof(Node));
    node->value = value;
    if (!head) {
        node->next = node;
        node->prev = node;
        list->next = node;
        return;
    }
    node->next = head;
    node->prev = head->prev;
    head->prev->next = node;
    head->prev = node;
}

void insert(Node *list, int index, int value) {
    Node *head = list->next;
    if (index == 0) {
        prepend(list, value);
        return;
    }
    else if (!head) return;
    Node *curr = head->next;
    int counter = 1;
    while (curr != head && counter < index) {
        ++counter;
        curr = curr->next;
    }
    if (counter == index) {
        Node *node = malloc(sizeof(Node));
        node->value = value;
        node->next = curr;
        node->prev = curr->prev;
        curr->prev->next = node;
        curr->prev = node;
    }
}

// deletion

int pop_left(Node *list) {
    Node *oldhead = list->next;
    if (!oldhead) return 0;
    else if (oldhead == oldhead->next) {
        int value = oldhead->value;
        free(oldhead);
        list->next = NULL;
        return value;
    }
    Node *newhead = oldhead->next;
    newhead->prev = oldhead->prev;
    oldhead->prev->next = newhead;
    list->next = newhead;
    int value = oldhead->value;
    free(oldhead);
    return value;
}

int pop_right(Node *list) {
    Node *head = list->next;
    if (!head) return 0;
    else if (head == head->next) {
        int value = head->value;
        free(head);
        list->next = NULL;
        return value;
    }
    Node *tail = head->prev;
    tail->prev->next = tail->next;
    tail->next->prev = tail->prev;
    int value = tail->value;
    free(tail);
    return value;
}

int delete(Node *list, int index) {
    if (index == 0) return pop_left(list);
    Node *head = list->next;
    if (!head) return 0;
    else if (head == head->next) {
        int value = head->value;
        free(head);
        list->next = NULL;
        return value;
    }
    int counter = 1;
    Node *curr = head->next;
    while (curr && curr != head && counter < index) {
        ++counter;
        curr = curr->next;
    }
    if (counter == index) {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        int value = curr->value;
        free(curr);
        return value;
    }
    return 0;
}

int *get_value_address(Node *list, int index) {
    Node *head = list->next;
    Node *curr = head;
    int counter = 0;
    while (curr && curr->next != head && counter < index) {
        curr = curr->next;
        ++counter;
    }
    if (counter == index) return &(curr->value);
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
