#include<iostream>
using namespace std;

class Stack{
	private:
		int *data;
		int length;
		int ms;
	public:
		Stack(int);
		bool push(int);
		int pop();
		void print();
		bool isEmpty();
};

Stack::Stack(int maxsize){
	data = new int[maxsize];
	length = 0;
	ms = maxsize;
}

bool Stack::push(int e){
	if(length>=ms)
		return 0;
	length++;
	for(int i=length-1;i>0;i--){
		data [i] = data [i-1];
	}
	data [0] = e;
	return 1;
}

int Stack::pop(){
	if(length<=0){
		return -1;
	}
	else {
		int a=data[length-1];
		for(int i=0;i<length-1;i++){
			data [i] = data [i+1];
		}
		length--;
		return a;
	}
}

void Stack::print(){
	for(int i=0;i<length;i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
	return;
}

bool Stack::isEmpty(){
	if(length==0)
		return 0;
	else
		return 1;
}


int main(){
	Stack a(10);
	a.push(1);
	a.print();
	a.push(2);
	a.print();
	a.pop();
	a.print();
	return 0;
}
