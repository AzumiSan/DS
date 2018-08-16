/*
*Heap
*heapyUp
*heapyDown
*heapyBuild
*heapysort
*heapify
*/
#include <iostream>
#include <conio.h>

using namespace std;

class heap{
	private:
		int *a;//data
		int length;
	public:
		heap(int);
		void heapyUp(int);// insert
		void heapyDown(); // delete
		void build(int *);
		void sort();
		void heapify(int *,int, int);
		void print();
};
void heap::build(int *a){
    for(int i = length/2; i>=1; i--){
		heapify(a,length, i);
	}
}

void heap::heapify(int *a, int n,int i){
	int l, r, largest;
  largest = i;
  l = 2*i; // left child
  r = 2*i + 1; // right child

  if (l < n && a[l] > a[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(a[i], a[largest]);

        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
  }

heap::heap(int n){
	a = new int[n];
    length = 0;
}

void heap::heapyUp(int n){
	int i = length;
	if(i == 0){
		a[i] = n;
		length++;
		return;
	}
	else{
	a[i] = n;
	while(a[i] >= a[(i-1)/2] && i>0){
			int tmp = a[i]; //nemegdsen utga
			a[i] = a[(i-1)/2]; //rootin utga
			a[(i-1)/2] = tmp;
			i = (i-1)/2;

		}
	length++;
	}

}

void heap::sort(){
    int i, n = length;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a,length,  i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(a[0], a[i]);

        // call max heapify on the reduced heap
        heapify(a,i,0);
    }
}

void heap::heapyDown(){
	int i = 0;
	int tmp;

	a[i] = a[length-1];
	heapify(a,length, i);
	length--;
}

void heap::print(){
	for(int i=0; i<length; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(){
	heap a(10);
	a.heapyUp(8);
	a.heapyUp(5);
	a.heapyUp(2);
	a.heapyUp(3);
	a.heapyUp(0);
	a.heapyUp(7);
	a.heapyUp(70);
    //a.sort();
    //a.heapyDown();
	a.print();
	return 0;
}

