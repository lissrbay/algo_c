#pragma once

typedef struct linked_list {
    int value;
    struct linked_list *next;
} llist;

struct lstack {
    llist *head;
    int size;
};

lstack* new_stack();

void delete_stack(lstack* stack);

void push(lstack* stack, int element);

int pop(lstack* stack);

bool isempty(lstack* stack);
