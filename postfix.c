#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// Stack operations
void push(char item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return stack[top--];
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch, x;

    push('(');  // Push initial '(' to stack
    strcat(infix, ")");  // Add ')' to end of infix expression

    while ((ch = infix[i++]) != '\0') {
        if (ch == ' ') continue;  // Skip spaces
        
        if (isalnum(ch)) {
            postfix[j++] = ch;  // Add operands directly to output
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        else {  // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    postfix[j] = '\0';  // Null-terminate the postfix string
}

int main() {
    char infix1[MAX_SIZE] = "A+B*C-D/E";
    char infix2[MAX_SIZE] = "(A+B)*(C-D)";
    char postfix[MAX_SIZE];

    // Test Case 1
    printf("Infix Expression 1: %s\n", infix1);
    infixToPostfix(infix1, postfix);
    printf("Postfix Expression: %s\n\n", postfix);

    // Test Case 2
    printf("Infix Expression 2: %s\n", infix2);
    infixToPostfix(infix2, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
