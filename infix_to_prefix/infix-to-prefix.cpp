/*
* Reserve infix to prefix expression
*/
# include <stdio.h>
# include <string.h>
# define MAX 20
#include <iostream>

using namespace std;
// total array size
void infixtoprefix(char infix[20],char prefix[20]);
//reserve infix to prefix
void reverse(char array[30]);
//tyhain stackees gargah
char pop();
//stack d push hiih
void push(char s);
//tyhain functionii operator mon esehiig shalgah.
int isOperator(char s);
//temdegtee shalgah
int prcd(int s);
int top=-1;
// array size
char stack[MAX];
//main
int main()
{
    char infix[20],prefix[20],temp;
    printf("Enter infix operation: ");
    gets(infix);
    infixtoprefix(infix, prefix);
    cout<<"prefix = ";
    reverse(prefix);
    puts((prefix));
}
//temdegt baihiin shalgaj mon bol stack d push hiiiih ugui bol pop hiih hesg uildel
void infixtoprefix(char infix[20],char prefix[20])
{
    int i,j=0;
    char s;
    stack[++top]='#';
    reverse(infix);
    // tyhain davtalt ni garaas avsan temdegtiin urtiin hemjeeg avah
    for (i=0; i<strlen(infix); i++)
    {
        s=infix[i];
        if (isOperator(s)==0)
        {
            prefix[j]=s;
            j++;
        }
        else
        {
            if (s==')')
            {
                push(s);
            }
            else if(s == '(')
            {
                while (stack[top]!=')')
                {
                    prefix[j]=pop();
                    j++;
                }
                pop();
            }
            else
            {
                // hervee garaas avsan utga ni temdeg bol stack ees gargah ugui bol pop hiih
                if (prcd(stack[top])<=prcd(s))
                {
                    push(s);
                }
                else
                {
                    while(prcd(stack[top])>=prcd(s))
                    {
                        prefix[j]=pop();
                        j++;
                    }
                    push(s);
                }

            }
        }

    }
    while (stack[top]!='#')
    {
        prefix[j]=pop();
        j++;
    }
    prefix[j]='\0';
}
//garaad infix expressionee hopbuulelt hiih
void reverse(char array[30])
{
    int i,j;
    char temp[100];
    for (i=strlen(array)-1, j = 0; i + 1 != 0; --i, ++j)
    {
        temp[j]=array[i];
    }
    temp[j]='\0';
    strcpy(array,temp);
    return;
}
//-temdegtee stack d pop hiih, pop hiisen utgaa butsan olgoh
char pop()
{
    char a;
    a=stack[top];
    top--;
    return a;
}
//temdegtee stack d push hiih
void push(char s)
{
    top++;
    stack[top]=s;
}
//temdegtuudee shalgah
int prcd(int s)
{
    switch(s)
    {
    case '+':
    case '-':
        return 2;
        break;
    case '*':
    case '/':
        return 4;
        break;
    case '$':
    case '^':
        return 6;
        break;
    case '#':
    case '(':
    case ')':
        return 1;
        break;
    }
}
//tyhain functionii temdegt mon bishiig shalgah
int isOperator(char s)
{
    switch(s)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '$':
    case '&':
    case '(':
    case ')':
        return 1;
        break;
    default:
        return 0;
    }
}
