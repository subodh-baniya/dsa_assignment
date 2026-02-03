#include<stdio.h>
#include<string.h>
#include <ctype.h>
#define Max 100
int stack[Max];
int top=-1;

//pushing character to stack
void push(char c){
    if(top==Max-1){
        printf("Too large expressin give an short one");
    }
    stack[++top]=c;
}

//popping the character from stack
char pop(){
    if(top==-1){
        printf("Stack Underflow");
    }
    return stack[top--];
}

//taking the element from stack top
char peek(){
     if(top==-1){
        printf("Stack Underflow");
    }
    return stack[top];
}

//setting precedance table
int precedance(char op){
    if(op=='*'||op=='/'){
        return 2;
    }
    if(op=='+'||op=='-'){
        return 1;
    }
    return 0;
}

//converting the infix to postfix
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

//evaluating the final result
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