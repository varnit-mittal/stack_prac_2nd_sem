#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct infix
{
    int top;
    int cap;
    char *arr;
} stack;

bool isEmpty(stack *s)
{
    if (s->top == -1)
        return true;
    return false;
}

stack *create(int cap)
{
    stack *s = (stack *)(malloc(sizeof(stack)));
    s->top = -1;
    s->cap = cap;
    s->arr = malloc(sizeof(char) * s->cap);
    return s;
}

void push(stack *s, char x)
{
    s->arr[++s->top] = x;
}

int pop(stack *s)
{
    if (isEmpty(s))
        return INT_MIN;
    else
        return s->arr[s->top--];
}

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '/' || ch == '^' || ch == '*');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void convert(char *inf)
{
    int len = strlen(inf);
    char *pre = malloc(sizeof(char) * (len + 1));
    stack *s = create(len);
    int i;
    int j = 0;
    for (i = len - 1; i >= 0; i--)
    {
        if (inf[i] == ' ' || inf[i] == '\t')
            continue;

        else if (isalnum(inf[i]))
            pre[j++] = inf[i];

        else if (inf[i] == ')')
            push(s, inf[i]);

        else if (inf[i] == '(')
        {
            if (s->top > -1 && s->arr[s->top] != ')')
                pre[j++] = pop(s);
            if (s->top > -1 && s->arr[s->top] != ')')
            {
                printf("Invalid Expression\n");
                return;
            }
            else
                pop(s);
        }

        else if (isOperator(inf[i]))
        {
            if (s->top > -1 && (precedence(s->arr[s->top]) >= precedence(inf[i])))
                pre[j++] = pop(s);
            push(s, inf[i]);
        }
    }
    while (s->top > -1)
    {
        if (s->arr[s->top] == ')')
        {
            printf("Invalid Expression\n");
            return;
        }
        else
            pre[j++] = pop(s);
    }
    pre[j] = '\0';
    printf("%s\n", pre);
    free(pre);
}

int main()
{
    char str[15]="x+y*z/w+u";
    convert(str);
}