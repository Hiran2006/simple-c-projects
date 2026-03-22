#include "calculator.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Basic arithmetic functions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    }
    return 0; // Error handling
}

// CharStack operations
void initCharStack(CharStack* s) {
    s->top = -1;
}

int isCharStackEmpty(CharStack* s) {
    return s->top == -1;
}

void pushChar(CharStack* s, char c) {
    if (s->top < 99) {
        s->items[++(s->top)] = c;
    }
}

char popChar(CharStack* s) {
    if (!isCharStackEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

char peekChar(CharStack* s) {
    if (!isCharStackEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

// DoubleStack operations
void initDoubleStack(DoubleStack* s) {
    s->top = -1;
}

int isDoubleStackEmpty(DoubleStack* s) {
    return s->top == -1;
}

void pushDouble(DoubleStack* s, double d) {
    if (s->top < 99) {
        s->items[++(s->top)] = d;
    }
}

double popDouble(DoubleStack* s) {
    if (!isDoubleStackEmpty(s)) {
        return s->items[(s->top)--];
    }
    return 0;
}

// Precedence function
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Infix to Postfix conversion
char* infixToPostfix(char* infix) {
    CharStack s;
    initCharStack(&s);
    char* postfix = (char*)malloc(200 * sizeof(char));
    int j = 0;
    int i = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i]) || infix[i] == '.') {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--; // Adjust for the loop increment
        } else if (infix[i] == '(') {
            pushChar(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isCharStackEmpty(&s) && peekChar(&s) != '(') {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            if (!isCharStackEmpty(&s) && peekChar(&s) == '(') {
                popChar(&s);
            }
        } else { // Operator
            while (!isCharStackEmpty(&s) && precedence(peekChar(&s)) >= precedence(infix[i])) {
                postfix[j++] = popChar(&s);
                postfix[j++] = ' ';
            }
            pushChar(&s, infix[i]);
        }
        i++;
    }

    while (!isCharStackEmpty(&s)) {
        postfix[j++] = popChar(&s);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
    return postfix;
}

// Evaluate Postfix
double evaluatePostfix(char* postfix) {
    DoubleStack s;
    initDoubleStack(&s);
    char* token = strtok(postfix, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            pushDouble(&s, atof(token));
        } else {
            double b = popDouble(&s);
            double a = popDouble(&s);
            switch (token[0]) {
                case '+': pushDouble(&s, add(a, b)); break;
                case '-': pushDouble(&s, subtract(a, b)); break;
                case '*': pushDouble(&s, multiply(a, b)); break;
                case '/': pushDouble(&s, divide(a, b)); break;
            }
        }
        token = strtok(NULL, " ");
    }
    return popDouble(&s);
}