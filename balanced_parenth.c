#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

typedef struct str_stack{
    int top;
    int capacity;
    char *str;
} stack;

stack * create(int capacity)
{
    stack *s=(stack *)(malloc(sizeof(stack)));
    s->capacity=capacity;
    s->top=-1;
    s->str=(char *)(malloc(sizeof(char)*s->capacity));
    return s;
}

bool isFull(stack *s)
{
    if(s->top==s->capacity-1)
    return true;
    else
    return false;
}

void push(stack *s, char c)
{
    if(isFull(s))
    return;
    s->str[++ s->top]=c;
}

bool isEmpty(stack *s)
{
    if(s->top <= -1)
    return true;
    else
    return false;
}

void pop(stack *s)
{
    if(isEmpty(s))
    return;
    s->top--;
}

bool isMatch(char a, char b)
{
    if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']'))
    return true;
    else
    return false;
}

bool isBalanced(char *str,stack *s)
{
    int i;
    // printf("%s",(str));
    for(i=0;i<strlen(str);i++)
    {
//        printf("%c",str[i]);
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        push(s,str[i]);
        else
        {
            if(isEmpty(s) == true)
            {
//                printf("!\n");
            return false;
            }
            else if(isMatch(s->str[s->top],str[i])==false)
            {
//                printf("!\n");
            return false;
            }
            else
            {
                
            pop(s);
            // printf("11%c",s->str[s->top]);
            }
        }
    }
    return(isEmpty(s));
}

int main()
{
    int n;
    scanf("%d",&n);
    stack *s= create(n);
    char str[n];
    int i;
    for(i=0;i<n;i++)
    scanf(" %c",&str[i]);
    str[i]='\0';
    // char c;
    // scanf("%c",&c);
//    printf("%s\n",str);
    if(isBalanced(str,s))
    printf("True string is balanced\n");
    else
    printf("False string is not balanced\n");
}
