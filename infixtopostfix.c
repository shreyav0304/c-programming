#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char infix[30], postfix[30], stack[30];
int top =-1;
void push(char item)
{
  stack[++top] = item;
}
char pop()
{
 char item;
 item = stack[top--];
 return item;
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^' || x == '$')
        return 3;
    return 0;
}
void main()
{
 int i,x,j=0;
 char symb;
 printf("\nEnter the valid infix expression:");
 scanf("%s",infix);
 for(i=0; infix[i] != '\0'; i++)
 {
 	symb = infix[i];
 	if(isalnum(symb))
 	  postfix[j++] = symb;
    else if(symb == '(')
            push(symb);
    else if(symb == ')')
        {
            while((x = pop()) != '(')
			    postfix[j++] = x;
 	    }
    else
        {
            while(priority(stack[top]) >= priority(symb))
  			    postfix[j++] = pop();
 	          push(symb);
        }
}
while(top > -1)
    postfix[j++] = pop();
 postfix[j] = '\0';
 printf("\nThe entered infix expression is :\n %s \n", infix);
 printf("\nThe corresponding postfix expression is :\n %s \n", postfix);
}
