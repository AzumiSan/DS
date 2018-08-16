/*
 *Hash function
 *Insert
 *Delete
 *Search
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Hash
{
    vector <int> arr; // array
    // hash ui array[i] iin ytgyydtai key ni holbogdono
    // indexes in arr[]
    map <int, int> Map;
public:
    // ug function ni hashd element nemne
    //log(n)
void add(int x)
{
        // If element ni ali hediin haisan  baihiin bol yu j hiihgui
    if(Map.find(x) != Map.end())
            return;
        // esreg tohioldold (else) elementee tavih (elementee haigaagui)
        int index = arr.size();
        arr.push_back(x);
        // tyhain index iin utgand ni element iin ytgiig tavih
        Map.insert(std::pair<int,int>(x, index));
}
// part of remove O(1)
void remove(int x)
{
         // element ee haij olooggui tohioldold butsaah
        if(Map.find(x) == Map.end())
            return;
        // dara ni tyhain element ee ystgah
        int index = Map.at(x); // tyhain element bgaa gazpiig zaah at
        Map.erase(x); // apilgah

        // swap with last element in arr
        // then remove element at back
        int last = arr.size() - 1;
        swap(arr[index], arr[last]);
        arr.pop_back();
        //hash husnegtiin suuliin element iig shine index iin ytgaap oopchloh
        Map.at(arr[index]) = index;
    }
    // if odoo baigaa elementiinn index eer bytsaah esreg tohioldold hooson utga bytsaah
int search(int x)
    {
        if(Map.find(x) != Map.end())
        return Map.at(x);
        return -1;
    }
};
// part of main
int main()
{
    Hash h;
    h.add(17); //0
    h.add(17);//1
    h.add(16);//2
    h.add(35);//3
    h.add(20);//4
    h.add(2);//5
    h.add(8);//6
    h.add(32);//7
    h.add(54);//8
    h.add(80);//9
    cout << h.search(80) << endl;
    cout << h.search(80) << endl;
    h.remove(54);
    h.remove(32);
    h.add(50);
    cout << h.search(50) << endl;
}
