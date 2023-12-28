#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 20

typedef struct Tower {
    int *array;
    int top, maxsize;
} Tower;

Tower *createTower(int maxsize) {
    Tower *tower = malloc(sizeof(Tower));
    tower->top = 0;
    tower->maxsize = maxsize;
    tower->array = calloc(maxsize, sizeof(int));
    return tower;
}

void deleteTower(Tower *tower) {
    if (!tower) return;
    if (tower->array) free(tower->array);
    free(tower);
}

void printTower(const Tower *tower) {
    if (!tower) {
        printf("Tower does not exist.\n");
        return;
    }
    int top = tower->top;
    putchar('[');
    if (top > 0) printf("%d", tower->array[top]);
    for (int i = 1; i < top; ++i)
        printf(", %d", tower->array[top+i]);
    printf("]\n");
}

bool push(Tower *tower, int n) {
    int top = tower->top;
    if (top > tower->maxsize) {
        printf("[Alert] Overflow.\n");
        return false;
    }
    tower->array[top] = n;
    ++(tower->top);
    return true;
}

int pop(Tower *tower) {
    if (tower->top <= 0) {
        printf("[Alert] Underflow.\n");
        return 0;
    }
    --(tower->top);
    return tower->array[tower->top];
}

int peek(const Tower *tower) {
    int top = tower->top;
    if (top <= 0 || top > tower->maxsize) {
        printf("[Error] Out of bounds of tower.\n");
        return 0;
    } 
    return tower->array[top-1];
}

void shiftTower(Tower *a, Tower *b, Tower *c) {
    if (a->top == 1)
        push(c, pop(a));
    else if (a->top == 2) {
        push(b, pop(a));
        push(c, pop(a));
        push(c, pop(b));
    }
    else if (a->top == 3) {
        push(c, pop(a));
        push(b, pop(a));
        push(b, pop(c));
        push(c, pop(a));
        push(a, pop(b));
        push(c, pop(b));
        push(c, pop(a));
    }
    else if (a->top > 3) {
        
    }
}

int main() {
    Tower *towerA = createTower(MAXSIZE);
    Tower *towerB = createTower(MAXSIZE);
    Tower *towerC = createTower(MAXSIZE);

    int values[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    for (int i = 0; i < sizeof(values)/sizeof(int); ++i)
        push(towerA, values[i]);

    shiftTower(towerA, towerB, towerC);
    printTower(towerC);

    deleteTower(towerA);
    deleteTower(towerB);
    deleteTower(towerC);
    return 0;
}
