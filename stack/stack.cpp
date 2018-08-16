#include<iostream>
using namespace std;
class Node{
		int data;
	    Node *next;
    public:
        Node(int e, Node *n){
        data = e;
        next = n;
    }
    friend class Stack;
};

class Stack{
	private:
		Node *top;
		int size;
	public:
		Stack();
		void push(int);
		int pop();
		void print();
		bool isempty();
};

Stack::Stack(){
	top = NULL;
	size = 0;
}

void Stack::push(int e){
	Node *temp = new Node(e, NULL);
	if(top == NULL){
		top = temp;
	}
	else{
		temp -> next = top;
		top = temp;
	}
	size++;
	}
int Stack :: pop(){

	if(!isempty()){
		Node *temp;
		if(size == 1){
			temp = top;
			top = NULL;

		}
		temp = top;
		top = top->next;
		return temp->data;

	}
return -1;
	//cout<<"\nstack hooson baina.";
}

void Stack::print(){
	for(Node *i=top; i!= NULL; i = i->next){
        cout<<i->data<<" ";
     }
     cout<<endl;
}

bool Stack::isempty(){
	if(top==NULL)
		return true;
	else
		return false;
}

int main(){
	Stack a;
	a.push(1);
	a.push(2);
	cout<<a.pop();
	cout<<a.pop();
	cout<<a.pop();
	a.print();

	return 0;
}
