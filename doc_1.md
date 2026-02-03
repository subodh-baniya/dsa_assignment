# Balanced Paranthesis Checker
This is the first question of the assignment where we have to check whether the given mathematical expression has balanced number of paranthesis or not.

## Data Structure
The program uses a stack implemented as an array.
```c 
#define Max 100
int stack[Max];
int top = -1;
```
- stack[Max] stores the opening parenthesis.
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

Adds a character (opening bracket) to the top of the stack.

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

3. int isMatch(char open, char close)
```c
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
```
Checks whether a popped opening bracket matches the current closing bracket.

4. int isBalance(char *expr)
```c
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
```
Determines if the entire expression has balanced brackets.

## Main Function Overview

```c
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
```
### Workflow of main function
- Reads a mathematical expression from the user.
- Calls isBalance() to check if brackets are balanced.
- Prints the result: Balanced or Not Balanced.

## Sample Output
- Sample 1:
- Sample 2:
- Sample 3:

