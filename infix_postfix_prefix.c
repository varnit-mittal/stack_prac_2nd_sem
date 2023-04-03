#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct stack{
    int top;
    int cap;
    char *arr;
} stack;
stack *create(int cap)
{
    stack *s=(stack *)(malloc(sizeof(stack)));
    s->top=-1;
    s->cap=cap;
    s->arr=malloc(sizeof(char)*s->cap);
    return s;
}

int precedence(char op)
{
    switch(op)
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
bool isOperator(char op)
{
    return (op=='/' || op== '+' || op=='*' || op=='-' || op=='^');
}
char * inf_post(char *inf)
{
    int len=strlen(inf);
    char *post= malloc(sizeof(char)*(len+1));
    stack *s=create(len);
    int i,j=0;
    for(i=0;i<len;i++)
    {
        if(inf[i]==' ' || inf[i]=='\t')
        continue;
        if(isalnum(inf[i]))
        {
            post[j]=inf[i];
            j++;
        }
        else if(inf[i]=='(')
        {
            s->arr[++s->top]=inf[i];
        }
        else if(inf[i]==')')
        {
            while(s->top>-1 && s->arr[s->top]!='(')
            post[j++]=s->arr[s->top--];
            if(s->top >-1 && s->arr[s->top]!='(')
            {
                printf("Invalid Expression");
                // return;
                break;
            }
            else{
                s->top--;
            }
        }

        else if(isOperator(inf[i]))
        {
            while(s->top>-1 && (precedence(s->arr[s->top])>precedence(inf[i])))
            post[j++]=s->arr[s->top--];
            s->arr[++s->top]=inf[i];
        }
    }
    while(s->top >-1)
    {
        if(s->arr[s->top]=='(')
        {
            printf("Invalid Expression\n");
            // return;
            break;
        }
        else
        post[j++]=s->arr[s->top--];
    }
    post[j]='\0';
    return post;
}
void inf_pre(char *inf)
{
    int len=strlen(inf);
    char *pre=malloc(sizeof(char)*(len+1));
    int i;
    for(i=0;i<len/2;i++)
    {
        char c=inf[i];
        inf[i]=inf[len-1-i];
        inf[len-1-i]=c;
    }
    for(i=0;i<len;i++)
    {
        if(inf[i]=='(')
        inf[i]=')';
        if(inf[i]==')')
        inf[i]='(';
    }
    pre = inf_post(inf);
    len=strlen(pre);
    for(i=0;i<len/2;i++)
    {
        char c=pre[i];
        pre[i]=pre[len-1-i];
        pre[len-1-i]=c;
    }
    printf("%s\n",pre);
}
int main()
{
    char infix[24]="x+y*z/w+u";
    inf_pre(infix);
}