#include <stdio.h>
#include <string.h>
#define Max 100
int stack[Max];
int top = -1;

//pushing the character to stack
void push(char c){
    if (top == Max - 1)
    {
        printf("Too large expression enter a short one");
    }
    stack[++top] = c;
}

//popping the character fron the stack
char pop(){
    if (top == -1)
    {
        return '\0';
    }
    return stack[top--];
}

//checks if the popped bracket from stack matches the bracket that we encounter
int isMatch(char open, char close){
    if (open == '(' && close == ')'){
        return 1;
    }
    if (open == '[' && close == ']'){
        return 1;
    }
    if (open == '{' && close == '}'){
        return 1;
    }
        return 0;
}

//gives the decision for finaal output of balanced or not
int isBalance(char *expr){
    top = -1;

    for (int i = 0; expr[i] != '\0'; i++){

        char ch = expr[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (top == -1)
                return 0;
            char popped = pop();
            if (!isMatch(popped, ch))
                return 0;
        }
    }

    return (top == -1);
}

int main(){
    char expr[Max];

    printf("Enter a mathematical expression:\n");
    scanf(" %[^\n]", expr);

    if (isBalance(expr)){
        printf("Balanced\n");
    }else{
        printf("Not Balanced\n");
    }

    return 0;
}