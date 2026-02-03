# Infix Expression Conversion To Postfix Expression
This is the second question of the assignment where we have to convert infix expression to postfix expression and evaluate it.

## Data Structure
The program uses a **stack** implemented as an array for two purposes:

1. Storing operators while converting infix to postfix.
2. Storing operands while evaluating the postfix expression.
```c 
#define Max 100
int stack[Max];
int top = -1;
```
- stack[Max] stores the parenthesis and operators duriing conversion.
- top keeps the track of current top of the stack.

## Functions Implemented

1. void push(char c)
```c
void push(char c){
    if (top == Max - 1)
    {
        printf("Too large expression enter a short one");
    }
    stack[++top] = c;
}
```

Adds a character (bracket and operator) to the top of the stack.

2. char pop()
```c
char pop(){
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    return stack[top--];
}
```
Removes and returns the top element from the stack.

3. char peek()
```c
char peek(){
     if(top==-1){
        printf("Stack Underflow");
    }
    return stack[top];
}

```
Returns the top element without removing it.

4. int precedance(char op)
```c
int precedance(char op){
    if(op=='*'||op=='/'){
        return 2;
    }
    if(op=='+'||op=='-'){
        return 1;
    }
    return 0;
}
```
Determines the precedence of an operator for conversion.

5. void conversionTopostfix(char *infix, char *postfix)
```c
void conversionTopostfix(char *infix, char *postfix){
        int k=0;
        
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[k++] = ch;        
        } 
        else if (ch == '(') {
            push(ch);                
        } 
        else if (ch == ')') {
            while (peek() != '(')     
                postfix[k++] = pop();
            pop();                     
        } 
        else { 
            while (top != -1 && precedance(peek()) >= precedance(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)                  
        postfix[k++] = pop();

    postfix[k] = '\0'; 

}
```
Converts an infix expression to postfix using a stack for operators.

6. int evaluate(char *postfix)
``` c
int evaluate(char *postfix){
    int stackvalue[Max], stackTop=-1;
     for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            stackvalue[++stackTop] = ch - '0'; 
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b = stackvalue[stackTop--];
            int a = stackvalue[stackTop--];
            switch(ch) {
                case '+': stackvalue[++stackTop] = a + b; break;
                case '-': stackvalue[++stackTop] = a - b; break;
                case '*': stackvalue[++stackTop] = a * b; break;
                case '/': stackvalue[++stackTop] = a / b; break;
            }
        }
    }
 return stackvalue[stackTop];

}
```
Evaluates a postfix expression using a stack for operands.

## Main Function Overview

```c
int main(){

        char infix[Max], postfix[Max];

    printf("Enter an infix expression (single-digit operands, + - * /):\n");
    scanf(" %[^\n]", infix);

    conversionTopostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluate(postfix);
    printf("Evaluated Result: %d\n", result);


    return 0;
}
```
### Workflow of main function
- Reads an infix expression from the user.
- Converts it to postfix using conversionTopostfix().
- Prints the postfix expression.
- Evaluates the postfix expression using evaluate().
- Prints the final result.

## Sample Output


