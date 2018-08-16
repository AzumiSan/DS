#include <iostream>
using namespace std;
class Node{

      int data;
      Node *next;
      public:
             Node(int e, Node *n){
                 data = e;
                 next = n;

             }

      friend class LinkedList;
};
class LinkedList{
      private:
         Node *head;
         int size;
      public:
         LinkedList();//
         ~LinkedList();//
         bool insert(int,int);
         void add(int);//
         void print();//
         bool del(int);//
		 int find(int);//
		 bool isEmpty();//
		 void sort(bool);
		 Node* get(int);//
};
LinkedList::LinkedList(){
      head = NULL;
      size=0;
}

LinkedList::~LinkedList(){
	Node* cur = head;
			while( cur != NULL ) {
			    Node* n = cur->next;
			    delete cur;
			    cur = n;
			}
			head = NULL;
			size = 0;
}

void LinkedList::add(int e){
     Node *n = new Node(e, NULL);
     if(head == NULL){
       head = n;
     }else{
       Node *i;
       for(i = head; i->next != NULL; i = i -> next){

       }
       i -> next = n;
    }

     size++;

}

bool LinkedList::isEmpty(){
	if(head==NULL)
		return false;
	else
		return true;
}

Node * LinkedList::get(int e){

  for(Node * i = head; i!=NULL; i = i ->next){
      if(i->data == e){
        return i;
      }
  }

  return NULL;
}

int LinkedList::find(int e){
	int k=0;
	for(Node * i=head;i!=NULL;i=i->next){
		//k++;
		if(i->data==e){
			return k;
		}
		k++;
	}

	return -1;
}

bool LinkedList::insert(int p,int e){
	if(p>size)
		return 0;
	Node *temp=new Node(e, NULL);
	if(head == NULL && p==0){
		head = temp;
	}
	else
		if(p==0){
		    temp->next=head;
		    head=temp;
		}
		else{
			Node *pre= new Node(0, NULL);
		    Node *cur= new Node(0, NULL);
		    Node *temp= new Node(e, NULL);
		    cur=head;
		    for(int i=0;i<p;i++)
		    {
		      pre=cur;
		      cur=cur->next;
		    }
		    pre->next=temp;
		    temp->next=cur;
		}
		size++;
		return 1;
}

bool LinkedList::del(int e){
	if(isEmpty() == 0 || find(e) == -1){
		return 0;
	}
	else
		if(size==1){
		if(head->data = e){
			head = NULL;
			size--;
			return 1;
		}
		else
			return 0;
	}
	if(find(e) == 0){
			Node *temp=new Node(0, NULL);
		    temp=head;
		    head=head->next;
		    delete temp;
		}
		if(find(e) == size-1){
			Node *cur=new Node(0,NULL);
		    Node *pre=new Node(0,NULL);
		    cur=head;
		    while(cur->next!=NULL)
		    {
		      pre=cur;
		      cur=cur->next;
		    }
		    //tail=pre;
		    pre->next=NULL;
		    delete cur;
		}
		Node *cur=new Node(0, NULL);
	    Node *pre=new Node(0,NULL);
	    cur=head;
	    for(int i=0;i<find(e);i++)
	    {
	      pre=cur;
	      cur=cur->next;
	    }
	    pre->next=cur->next;
	    size--;
	    return 1;
}

void LinkedList::sort(bool n){
	Node *i, *j;
	int a;
	int k=0;
	int k1=0;
	if(n == true){

		for(i = head, k=0; i->next!= NULL; i = i -> next, k++){
			for(j=head, k1=0;k1<size-k-1; j=j->next, k1++){
				if(j->data > j->next->data){
					a = j->data;
					j->data = j->next->data;
					j->next->data = a;
				}
			}
	   	}
	}
	else{
		for(i = head, k=0; i->next!= NULL; i = i -> next, k++){
			for(j=head, k1=0; k1<size-k-1; j=j->next, k1++){
				if(j->data < j->next->data){
					a = j->data;
					j->data = j->next->data;
					j->next->data = a;
				}
			}
	   	}
	}
}

void LinkedList::print(){
     for(Node *i=head; i!= NULL; i = i->next){
        cout<<i->data<<" ";
     }
     cout<<endl;
}


int main()
{
    LinkedList m;
    m.add(1);
    m.print();
    m.add(2);
    m.print();
   	m.insert(0,5);
   	m.print();
	m.insert(2,9);
    m.print();//4
    m.del(1);
    m.print();
    m.del(5);
    m.print();
	m.del(3);
	m.print();
	m.add(8);
	m.print();
	m.add(6);
	m.print();
	m.add(4);
	m.print();
	m.add(8);
	m.print();
	m.sort(true);
	m.print();

	//cout<<endl;
//	system("pause");
    return 0;
}
