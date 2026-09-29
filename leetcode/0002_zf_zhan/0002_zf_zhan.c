#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char * s){
    int len = strlen(s);
    char* stack = (char*)malloc(len * sizeof(char));
    if(stack == NULL)
        return false;
    int top = -1;

    for(int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;
        }
        else
        {
            if(top == -1)
            {
                free(stack);
                return false;
            }
            char left = stack[top];
            if( (ch == ')' && left == '(') ||
                (ch == '}' && left == '{') ||
                (ch == ']' && left == '[') )
            {
                top--;
            }
            else
            {
                free(stack);
                return false;
            }
        }
    }
    free(stack);
    return top == -1;
}

int main(void)
{
    char s1[] = "(}[]";
    printf("%d\n", isValid(s1));
    return 0;
}