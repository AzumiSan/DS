#include <iostream>
using namespace std;
class NODE{
public:
    int data;
    NODE *next;
    NODE *prev;
public:
    NODE(int d , NODE *n, NODE *p){
    data=d;
    next=n;
    prev=p;
    }
    friend class QUEUE;
};
class QUEUE{
private:
    NODE *front; // daraalliin ehnii element;
    NODE *rear; // daraalliin togsgoliin element
    int size;  // daraalald bgaa elelementiin too
public:
    QUEUE();
    bool enqueue(int, int);// void
    void dequeue();
    void print();
    int isEmpty();
    ~QUEUE();
};

QUEUE::QUEUE()
{
    front=rear=NULL;
    size=0;
}
/*
*enqueue
*/
/*bool QUEUE::enqueue(int p , int e )
{
    NODE * temp = new NODE();
    temp->data=value;
    if(temp == NULL)
    {
        cout<<"fulllll";
        return;
    }
    temp->data=value;
     //hervee daraalal hooson bval
    if(front==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next =temp;
        rear=rear->next;
    }
    size++;
}*/
bool QUEUE :: enqueue (int p, int e){
    NODE *part = new NODE(e, NULL, NULL);
    if(size == 0){
        if(p == 0){
            front = part;
            size++;
        }
    }else{
        NODE *temp = front;
        NODE *prev;
        int oldSize = size;
        for(int i = 0; i < oldSize; i++)
        {
            if(i == p - 1)
            {
                prev = temp;
            }else if(i == p){
                if(p == 0){
                    front = part;
                    part->next = temp;
                    temp->prev = part;
                }else{
                    prev->next = part;
                    part->prev = prev;
                    part->next = temp;
                    temp->prev = part;
                }
                size++;
            }
            // tyuhain listiin togsgold nemne
            if(temp->next == NULL){
                if(p == size){
                    temp->next = part;
                    part->prev = temp;
                    size++;
                }
            }else{
                //tyhain listiin araagiin element-g hadgalna
                temp = temp->next;
            }
        }
    }
}
/*
*print
*/
void QUEUE::print(){
    NODE * current = front;
    NODE * last;
    while(current != NULL){
        cout<<current->data<<" ";
        last = current;
        current = current->next;
    }
    cout<<endl;
    while(last !=NULL){
        cout<<last->data<<" ";
        last = last->prev;
    }
    cout<<endl;
}

/*void QUEUE::print(){
    if(front == NULL){
        cout<<"\n emptyy";
        return;
    }
    NODE *tempNode;
    tempNode=front;
    while(tempNode !=NULL)
    {
        cout<<tempNode->data<<" ";
        tempNode = tempNode->next;
        }
        cout<<endl;
}
 while(last !=NULL){
      cout<<tempNode->data<<" ";
      tempNode = tempNode->prev;
    }

    cout<<endl;
}*/
/*
*dequeue
*/

void QUEUE::dequeue()
{
    if(front == NULL)
    {
        cout<<"\n Daraalal hooson bn";
        return;
    }

    NODE *tempNode;
    tempNode =front;
    cout<<"\n ystgaj bui utga : "<<front->data<<" ";
    if(size >0)
    {
        front = tempNode->next;
        size--;
        delete tempNode;
    }
}
/*
*empty
*/

int QUEUE::isEmpty(){
    if(front==NULL){
        return 1;
    }
    else return 0;
}

QUEUE::~QUEUE(){
    if(front == NULL){
        return;
    }
    NODE *tempNode;
    tempNode= front;
    if(size>0){
        front = tempNode->next;
        size--;
        delete tempNode;
    }
}
/*
*main
*/
int main()
{
    QUEUE data;
    data.enqueue(1,3);
	data.enqueue(2,4);
	data.print();
	data.dequeue();
	//data.enqueue(6);
	//data.print();
	//data.print();
    return 0;
}
