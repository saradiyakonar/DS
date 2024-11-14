#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

struct Stack {
    char items[MAX_STACK_SIZE];
    int top;
};

void init(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->items[++stack->top] = item;
    }
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return '\0';
}

char peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top];
    }
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

void infixToPostfix(const char* infix) {
    struct Stack stack;
    init(&stack);
    int infixLength = strlen(infix);

    for (int i = 0; i < infixLength; i++) {
        char currentChar = infix[i];

        if (isalnum(currentChar)) {
            printf("%c", currentChar);
        }
        else if (currentChar == '(') {
            push(&stack, currentChar);
        }
        else if (currentChar == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                printf("%c", pop(&stack));
            }
            if (!isEmpty(&stack) && peek(&stack) == '(') {
                pop(&stack);
            }
        }
        else {
            while (!isEmpty(&stack) && precedence(currentChar) <= precedence(peek(&stack))) {
                printf("%c", pop(&stack));
            }
            push(&stack, currentChar);
        }
    }
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
}

int main() {
    const char* infixExpression = "a+b*(c-d)/e";
    printf("Infix expression: %s\n", infixExpression);
    printf("Postfix expression: ");
    infixToPostfix(infixExpression);
    return 0;
}