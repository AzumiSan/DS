
#include <iostream>
using namespace std;


class node
{
public:
    char data;
    node *left;
    node *right;
    void ExpTree(char *suffix);
    void preOrder(node *tree);
    void postOrder(node *tree);
    void inOrder(node *tree);
};

char prefix[35];
int top=-1;
node *arr[35];
node *pop()
{
    top--;
    return(arr[top+1]);
}


int  r(char c)
{
    //for checking symbol is operand or operatorif(inputchar=='+' || inputchar=='-' || inputchar=='*' || inputchar=='/')
    if (c == '+' || c == '-' || c == '/' || c== '*' || c == '%')
        return(-1);
    else if(c >= 'a' || c <= 'z')
        return(1);
    else if(c >= 'A' || c <= 'Z')
        return(1);
    else if (c == ' ')
        return(0);
    else
        return(-99);  //for error
}
void push(node *tree)
{
    top++;
    arr[top]=tree;
}

void ExpTree(char *suffix)
{
    char symbol;
    node *newl,*ptr1,*ptr2;
    int flag;
    symbol = suffix[0];
    for(int i = 1; symbol !=NULL; i++)
    {
        flag = r(symbol);
        if(flag == 1)
        {
            newl = new node;
            newl->data = symbol;
            newl->left = NULL;
            newl->right = NULL;
            push(newl);
        }
        else if (flag == -1)
        {
            //If the symbol is operator//pop two top elements.
            ptr1=pop();
            ptr2=pop();
            newl = new node;
            newl->data = symbol;
            newl->left = ptr2;
            newl->right = ptr1;
            push(newl);
        }
        else if (flag == 0)
            symbol = suffix[i]; // If symbol is a space, skip.
        symbol=suffix[i];
    }
}


void preOrder(node *tree)
{
    if( tree!=NULL)
    {
        cout << tree->data << " ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}


void inOrder(node *tree)
{
    if( tree!=NULL)
    {
        inOrder(tree->left);
        cout << tree->data << " ";
        inOrder(tree->right);
    }
}


void postOrder(node *tree)
{
    if( tree!=NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->data << " ";
    }
}
int main()
{
    char choice = 'Y';


    if (choice == 'Y')
    {
        cout<<"Please enter a Prefix Expression:  ";
        cin>>prefix;


        //Creation of Expression Tree
        ExpTree(prefix);


        //Traversal Operation on expression tree
        cout << "In-Order Traversal:   ";
        inOrder(arr[0]);
        //cout >> endl;


        cout << "Pre-Order Traversal:  ";
        preOrder(arr[0]);
        cout << endl;


        cout << "Post-Order Traversal: ";
        postOrder(arr[0]);
        cout << endl;

        cout << "Would you like to enter another question (Y or N)?  ";
        cin >> choice;
        choice = toupper(choice);
    }
    else if (choice != 'Y' && choice != 'N')
    {
        cout << "ERROR:  Invalid choice.  Please enter only Y or N:  ";
        cin >> choice;
        choice = toupper(choice);
    }
    else
    {
        return 0;
    }
}




