#ifndef CALCULATOR_H
#define CALCULATOR_H

// Basic arithmetic functions
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Stack structures
typedef struct {
    int top;
    char items[100];
} CharStack;

typedef struct {
    int top;
    double items[100];
} DoubleStack;

// Stack operations
void initCharStack(CharStack* s);
int isCharStackEmpty(CharStack* s);
void pushChar(CharStack* s, char c);
char popChar(CharStack* s);
char peekChar(CharStack* s);

void initDoubleStack(DoubleStack* s);
int isDoubleStackEmpty(DoubleStack* s);
void pushDouble(DoubleStack* s, double d);
double popDouble(DoubleStack* s);

// Expression parsing
int precedence(char op);
char* infixToPostfix(char* infix);
double evaluatePostfix(char* postfix);

#endif // CALCULATOR_H