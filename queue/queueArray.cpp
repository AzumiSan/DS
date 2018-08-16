#include<iostream>
using namespace std;
class Queue{
	private:
		int *data;
		int length;
		int ms;
	public:
		Queue(int);
		bool enqueue(int);
		int dequeue();
		void print();
		bool isEmpty();
};

Queue::Queue(int maxsize){
	data = new int[maxsize];
	length = 0;
	ms = maxsize;
}

bool Queue::enqueue(int e){
	if(length>=ms)
		return 0;
	length++;
	for(int i=length;i>0;i--){
		data[i]=data[i-1];
	}
	data[0]=e;
	return 1;
}

int Queue::dequeue(){
	if(length<=0){
		return -1;
	}
	else {
		int a;
		a=data[length-1];
		length--;
		return a;
	}
}

void Queue::print(){
	for(int i=0;i<length;i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
	return;
}

bool Queue::isEmpty(){
	if(length==0)
		return 0;
	else
		return 1;
}
int main(){
	Queue data(10);
	data.enqueue(4);
	data.print();
	data.enqueue(5);
	data.print();
	data.enqueue(6);
	data.print();
	data.dequeue();
	data.print();
	return 0;
}
