#include <iostream>
#include <malloc.h>
#include "stack.h"
using namespace std;

lstack* new_stack() {
    lstack *stack = new lstack[1];
    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void delete_stack(lstack *stack) {
    llist *next, *cur_pointer = stack->head;
    while (cur_pointer) {
        next = cur_pointer->next;
        free(cur_pointer);
        cur_pointer = next;
    }
    free(stack);
}

void push(lstack *stack, int element) {
    llist *node = new llist[1];
    node->value = element;
    node->next = NULL;
    stack->head = node;
    stack->size++;
}

int pop(lstack *stack) {
    if (stack->size > 0) {
        int result = stack->head->value;
        llist *node = stack->head->next;
        free(stack->head);
        stack->head = node;
        stack->size = 0;
        return result;
    }
    else {
        cout << "Stack is empty.";
        return 0;
    }
}

bool isempty(lstack *stack) {
    return stack->size == 0;
}

int main()
{
    return 0;
}
