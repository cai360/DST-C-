//
//  main.c
//  Stack_implement_Linked_List
//
//  Created by cai on 2025/6/4.
//

#include <stdio.h>
#include <stdlib.h>


struct Stack{
    struct Node *topPtr;
    int size;
};

struct Node{
    int data;
    struct Node *nextPtr;
};

void initStack(struct Stack **stack){
    *stack = malloc(sizeof(struct Stack));
    (*stack)->topPtr = NULL;
    (*stack)->size = 0;
    
}

void push(struct Stack *stack, int d){
    struct Node *newNodePtr = (struct Node *)malloc(sizeof(struct Node));
    newNodePtr->data = d;
    newNodePtr->nextPtr = stack->topPtr;

    stack->topPtr = newNodePtr;
    stack->size += 1;
}

int pop(struct Stack *stack){
    if(stack->topPtr != NULL){
        struct Node *deletePtr = stack->topPtr;
        int value = deletePtr->data;
        
        stack->topPtr = deletePtr->nextPtr;
        stack->size--;
        free(deletePtr);
        return value;
    }
    printf("Stack is empty.\n");
    return -1;
}

int isEmpty(struct Stack *stack){
    if(stack->topPtr == NULL){
        return 1;
    }
    return 0;
}

int peek(struct Stack *stack){
    if(stack->topPtr != NULL)
    {
        return stack->topPtr->data;
    }
    return -1;
}

void printStack(struct Stack *stack){
    struct Node *currPtr = stack->topPtr;
    while(currPtr != NULL){
        printf("%d ", currPtr->data);
        currPtr = currPtr->nextPtr;
    }
    
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct Stack *stackPtr;
    initStack(&stackPtr);
    push(stackPtr, 1);
    push(stackPtr, 2);
    push(stackPtr, 3);
    pop(stackPtr);
    printStack(stackPtr);
    
    

    return 0;
}
