#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>
#include<math.h>

typedef struct stack_postfix{
    int top;
    int cap;
    int *arr;
} stack;

stack *create(int cap)
{
    stack *s=(stack *)(malloc(sizeof(stack)));
    s->top=-1;
    s->cap=cap;
    s->arr=malloc(sizeof(int)*(s->cap));
    return s;
}

bool isEmpty(stack *s)
{
    return s->top==-1;
}

int pop(stack *s)
{
    if(isEmpty(s))
    return INT_MIN;
    return s->arr[s->top--];
}

void push(stack *s, int ch)
{
    s->arr[++s->top]=ch;
}

int isOperator(char ch)
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='^' || ch=='/')
    return 1;
    else
    return 0;
}

int eval(char *post)
{
    int len=strlen(post);
    stack *s= create(len);
    int i,k=0;
    char *str=malloc(sizeof(char)*8);
    for(i=0;i<=len;i++)
    {
        if(!isOperator(post[i]))
        {
            while(post[i]!=' ' && post[i]!='\0')
            {
                str[k]=post[i];
                k++;
                i++;
            }
            str[k]='\0';
            int m;
            int g=strlen(str)-1;
            int t=0;
            for(m=0;m<strlen(str);m++)
            {
              int b=(str[m]-'0');
                t=t+b*pow(10,g);
                g--;
            }
            push(s,t);
            str=malloc(sizeof(char)*8);
            k=0;
        }
        else
        {
            int a= pop(s);
            int b=pop(s);
            if(a!=INT_MIN && b!=INT_MIN)
            {
                switch(post[i])
                {
                    case '+':
                    push(s,b+a);
                    break;
                    case '-':
                    push(s,b-a);
                    break;
                    case '*':
                    push(s,a*b);
                    break;
                    case '/':
                    push(s,b/a);
                    break;
                    case '^':
                    push(s,pow(b,a));
                }
                i++;
            }
        }
    }
    return s->arr[s->top];
}

int main()
{
    char exp[]= "100 200 + 2 / 5 * 7 +";

    printf("Evaluation : %d\n",eval(exp));
    return 0;
}