#include<iostream>
#include<vector>

using namespace std;
vector <vector<int> > arr;

class hashE{
private:
    int n;
public:
    int size;
    hashE(int n);
    void del(int );
    void isEmpty();
    void add(int);
    int findS(int);
    void print();
};
hashE::hashE(int n)
{
    size = n;
    arr.resize(n);

}
/*void hashE::isEmpty()
{
    if(size()== 0)
		return 0;
	else
		return 1;
}
*/
void hashE::del(int z)
{
    int i=z%size;
    int j=findS(z);
    arr[i].erase(arr[i].begin() +j);
    //int last = arr.size()-1;
    //swap(arr[i], arr[last]);
    //arr.pop_back();
    //hashE.at(arr[i])=i;
}
void hashE::add(int z)
{
    int i=z%size;
    arr[i].push_back(z);

}
int hashE:: findS(int z)
{
    int i = z%size;
    for(int j=0;j<arr[i].size();j++)
        if(arr[i][j]==z)
        return j;
}
void hashE::print()
{
    for(int i=0;i<size;i++){
        cout<<i<<"=>";
    for(int j=0;j<arr[i].size();j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
    }
    cout<<"--------"<<endl;
}
int main()
{
 hashE h(11);
 h.add(54);
 h.add(28);
 h.add(17);
 h.add(17);
 h.add(77);
 h.add(1);
 h.add(88);
 h.print();
 h.del(1);
 h.print();
 return 0;

}
