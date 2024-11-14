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
    return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2 : 0;
}

void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void infixToPrefix(const char* infix) {
    struct Stack stack;
    init(&stack);
    int infixLength = strlen(infix);

    char* prefix = (char*)malloc(infixLength * sizeof(char));
    int prefixIndex = 0;

    for (int i = infixLength - 1; i >= 0; i--) {
        char currentChar = infix[i];

        if (isalnum(currentChar)) {
            prefix[prefixIndex++] = currentChar;
        } else if (currentChar == ')') {
            push(&stack, currentChar);
        } else if (currentChar == '(') {
            while (!isEmpty(&stack) && peek(&stack) != ')') {
                prefix[prefixIndex++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) == ')') {
                pop(&stack);
            }
        } else {
            while (!isEmpty(&stack) && precedence(currentChar) < precedence(peek(&stack))) {
                prefix[prefixIndex++] = pop(&stack);
            }
            push(&stack, currentChar);
        }
    }

    while (!isEmpty(&stack)) {
        prefix[prefixIndex++] = pop(&stack);
    }

    prefix[prefixIndex] = '\0';
    reverseString(prefix);
    printf("%s\n", prefix);

    free(prefix);
}

int main() {
    const char* infixExpression = "a+b*(c-d)/e";
    printf("Infix expression: %s\n", infixExpression);
    printf("Prefix expression: ");
    infixToPrefix(infixExpression);
    return 0;
}