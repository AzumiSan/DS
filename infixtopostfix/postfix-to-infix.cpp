/* postfix to infix tuhain program ni 5 toliin operator tai.
infix expression mon esehiih shalgah
*/

#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>
#include<iostream>

#define SIZE 100


/*total stack size
*/
char stack[SIZE];
int top = -1;

/* stack puu push hiih operation iig todophoiloh */

void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack full.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

/* function operator iin pop hiih uildliig todophoiloh */
char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		/* tyhain ilephiilel ni bupuu baihiig shalgah */
		exit(1);
	}
	//esreg tohioldol tyhain stack deh ytgiig hiin bytsaah
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

/* tyhain functionii operator mon esehiig shalgan mon bol 1 ugui bol 0 ytga butsaah */

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

/* tyhian functionii operatort ni iluu davuu erh edluleh heheh.
* tyhain temdegtuud ni ihees baga opuugaa epemblegdsen bdag tyl uniig hapuulah
higher ni ^ -> *->+ etc
 */

int precedence(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;

	push('(');                               /* push '(' onto stack */
	strcat(infix_exp,")");                  /* add ')' to infix expression */

	i=0;
	j=0;
	item=infix_exp[i];         /* initialize before loop*/

	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item) || isalpha(item))
		{
			postfix_exp[j] = item;              /*postfix exp d hepeglegdeh operand iig stack d nemeh */
			j++;
		}
		else if(is_operator(item) == 1)        /* operator mon eseh */
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j] = x;                  /* ondop tuvshnii operator mon eseh */
				j++;
				x = pop();                       /*  postfix expresion d stackd operator nemeh */
			}
			push(x);
			/* davtakt dyyssanii daraa tyhain heseg uildel ajillahgui*/

			push(item);                 /*  stackd odoo hiigdej  bgaa uildliig temdegtiig nemeh */
		}
		else if(item == ')')         /* if odoo bsan  symbol is ')' then */
		{
			x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix_exp[j] = x;
				j++;
				x = pop();
			}
		}
		else
		{ /* hervee odoo bgaa temdegt bhgui bol */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix_exp[i]; /* infix iin daragin operator ig avah */
	} /* while loop ends here */
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* ene ni temdegt bish bolohiig ilephiileh */
		getchar();
		exit(1);
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* temdegt bish eseh */
		getchar();
		exit(1);
	}
	postfix_exp[j] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */
}
/* main function begins */
int main()
{
	char infix[SIZE], postfix[SIZE];         /* postfin exp avah utgiin hemjeeg hapuulah */
	printf("infix to prefic expresion");
	printf("\nEnter Infix expression : ");
	gets(infix);
	InfixToPostfix(infix,postfix);                   /* convert hiisen uildlee duudah */
	printf("Postfix Expression: ");
	puts(postfix);                     /* print postfix expression */
	return 0;
}
